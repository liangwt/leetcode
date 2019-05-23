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

#include <inttypes.h>
#include <stdlib.h>

typedef struct _hash_type {

    // compute hash value
    uint64_t (*hash_function)(const void *key);

    // duplicate key
    void *(*key_dup)(void *privdata, const void *key);

    // duplicate value
    void *(*val_dup)(void *privdata, const void *val);

    // compare hash value
    int (*key_compare)(void *privdata, const void *key1, const void *key2);

    // destroy key
    void (*key_destructor)(void *privdata, void *key);

    // destroy value
    void (*val_destructor)(void *privdata, void *val);

} hash_type;

typedef struct _bucket {
    void *key;

    union {
        void *val;
        uint64_t u64;
        int64_t s64;
        double d;
    } v;

    struct _bucket *next;
} bucket;

typedef struct _hash_map {
    hash_type type;
    void *privdata;
    unsigned long used;
    unsigned long size;
    unsigned long mask;
    bucket *buckets[];
} hash_map;

typedef struct _hash_iterator {
    hash_map *hm;
    long index;
    bucket *bucket, *next_bucket;
} hash_iterator;

#define hash_map_len(hm) (hm->used)

#define hash_map_get_uint_value(bucket) ((bucket)->v.u64)

#define hash_map_get_uint_key(bucket) (*(int *)(bucket)->key)

hash_type INT_KEY_INT_VALE;

hash_map *hash_map_init(unsigned long size, hash_type type, void *privdata);

void hash_map_uint_put(hash_map *hm, void *key, uint64_t val);

int hash_map_uint_get(hash_map *hm, void *key, uint64_t *val);

void hash_map_destroy(hash_map *hm);

void hash_map_bucket_destroy(hash_map *hm, bucket *bk);

hash_iterator *hash_iterator_init(hash_map *hm);

bucket *hash_iterator_next(hash_iterator *hi);

bucket *hash_iterator_cur(hash_iterator *hi);