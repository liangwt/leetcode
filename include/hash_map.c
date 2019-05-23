/**
 * Map implementation by hash table
 *
 * Copyright 2019 liang.w.t@foxmail.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 **/

#include "hash_map.h"

uint64_t int_hash_function(const void *key) {
    int i = *((int *) key);

    return i < 0 ? (uint64_t) (-i) : (uint64_t) i;
}

int int_key_compare(void *privdata, const void *key1, const void *key2) {
    return *((unsigned int *) key1) == *((unsigned int *) key2);
}

hash_type INT_KEY_INT_VALE = {
    int_hash_function,
    NULL,
    NULL,
    int_key_compare,
    NULL,
    NULL
};

hash_map *hash_map_init(unsigned long size, hash_type type, void *privdata) {
    hash_map *hm = malloc(sizeof(hash_map) + sizeof(bucket *) * size);

    hm->type = type;
    hm->privdata = privdata;
    hm->used = 0;
    hm->size = size;
    hm->mask = size - 1;

    // reset buckets
    for (int i = 0; i < size; ++i) {
        hm->buckets[i] = NULL;
    }

    return hm;
}

void hash_map_destroy(hash_map *hm) {
    hash_iterator *hi = hash_iterator_init(hm);

    while (hash_iterator_next(hi)) {
        bucket *bk = hash_iterator_cur(hi);
        hash_map_bucket_destroy(hm, bk);
    }

    free(hm);
}

void hash_map_bucket_destroy(hash_map *hm, bucket *bk) {
    if (hm->type.key_destructor) {
        hm->type.key_destructor(hm->privdata, bk->key);
    }

    if (hm->type.val_destructor) {
        hm->type.val_destructor(hm->privdata, bk->v.val);
    }

    free(bk);
}

long hash_map_key_idx(hash_map *hm, void *key, bucket **bk) {
    uint64_t hash = hm->type.hash_function(key);
    unsigned long idx = hash & hm->mask;
    *bk = NULL;

    // not exist element at the idx
    if (hm->buckets[idx] == NULL) {
        return idx;
    }

    bucket *ref = hm->buckets[idx];

    while (ref) {
        if (hm->type.key_compare(hm->privdata, ref->key, key) || ref->key == key) {
            *bk = ref;
            break;
        }
        ref = ref->next;
    }

    return idx;
}

//void hash_map_key_del(hash_map *hm, void *key) {
//    unsigned int hash = hm->type.hash_function(key);
//    unsigned long idx = hash & hm->mask;
//
//    // not exist element at the idx
//    if (hm->buckets[idx] == NULL) {
//        return;
//    }
//
//    bucket *ref = hm->buckets[idx];
//
//    while (ref) {
//        if (hm->type.key_compare(hm->privdata, ref->key, key) || ref->key == key) {
//
//            break;
//        }
//        ref = ref->next;
//    }
//
//    return;
//}

bucket *hash_map_locate(hash_map *hm, void *key) {
    bucket *bk = NULL;
    long idx = hash_map_key_idx(hm, key, &bk);

    // not exist
    if (bk == NULL) {
        bk = malloc(sizeof(bucket));
        if (bk == NULL) {
            return NULL;
        }

        // set key
        bk->key = key;

        // add operation
        bk->next = hm->buckets[idx];
        hm->buckets[idx] = bk;

        // maintain
        hm->used++;
    }

    return bk;
}

bucket *hash_map_get(hash_map *hm, void *key) {
    bucket *bk = NULL;
    hash_map_key_idx(hm, key, &bk);

    return bk;
}

void hash_map_uint_put(hash_map *hm, void *key, uint64_t val) {
    bucket *bk = hash_map_locate(hm, key);
    bk->v.u64 = val;
}

int hash_map_uint_get(hash_map *hm, void *key, uint64_t *val) {
    bucket *bk = hash_map_get(hm, key);
    if (bk == NULL) {
        return -1;
    }
    *val = hash_map_get_uint_value(bk);
    return 0;
}

hash_iterator *hash_iterator_init(hash_map *hm) {
    hash_iterator *hi = malloc(sizeof(hash_iterator));

    hi->hm = hm;
    hi->index = -1;
    hi->bucket = NULL;
    hi->next_bucket = NULL;

    return hi;
}

/**
 * get the next bucket of hash_map
 *
 * attention please:
 *
 * next_bucket maintain for hash_iterator->bucket may be released or modified while iterating
 *
 * @param hi
 * @return
 */
bucket *hash_iterator_next(hash_iterator *hi) {
    // iterate same index
    if (hi->next_bucket) {
        hi->bucket = hi->next_bucket;
        hi->next_bucket = hi->next_bucket->next;
        return hi->bucket;
    }

    // move to next index
    for (long i = hi->index + 1; i < hi->hm->size; ++i) {
        bucket *bk = hi->hm->buckets[i];
        if (bk != NULL) {
            hi->index = i;
            hi->bucket = bk;
            hi->next_bucket = bk->next;
            return hi->bucket;
        }
    }

    return NULL;
}

bucket *hash_iterator_cur(hash_iterator *hi) {
    return hi->bucket;
}