/**
 * Given a non-empty array of integers, return the k most frequent elements.
 *
 * Example 1:
 *
 * Input: nums = [1,1,1,2,2,3], k = 2
 * Output: [1,2]
 * Example 2:
 *
 * Input: nums = [1], k = 1
 * Output: [1]
 * Note:
 *
 * You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
 * Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
 *
**/

#include <stdio.h>
#include "include/hash_map.h"

int *topKFrequent(int *nums, int numsSize, int k, int *returnSize);

int main() {
    int nums[] = {1, 1, 1, 2, 2, 3}, k = 2;
    int returnSize;

    int *ret = topKFrequent(nums, sizeof(nums) / sizeof(int), k, &returnSize);
    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", ret[i]);
    }
}

/**
 * 第一步使用map来统计每一个数字出现次数，此步时间复杂度为O(n)空间复杂度O(n)
 * 第二步可以使用桶排序来按照出现的频次排序，此处我们直接使用和待统计的数字数目一样大小的桶，所以时间复杂度为O(n)空间复杂度O(n)
 *
 * @param nums
 * @param numsSize
 * @param k
 * @param returnSize
 * @return
 */
int *topKFrequent(int *nums, int numsSize, int k, int *returnSize) {
    hash_map *hm = hash_map_init((unsigned long) numsSize, INT_KEY_INT_VALE, NULL);
    uint64_t val;

    // 统计每个数字出现的频率
    for (int i = 0; i < numsSize; ++i) {

        int ret = hash_map_uint_get(hm, (void *) &nums[i], &val);
        if (ret == -1) {
            hash_map_uint_put(hm, (void *) &nums[i], 1);
        } else {
            hash_map_uint_put(hm, (void *) &nums[i], val + 1);
        }

    }

    // 桶排序

    // 初版方案：
    //
    // 排序桶是一个二维数组，当两个元素相同时，放入同一个桶位中
    // 0 => [ a, b]
    // 1 => [ c, d]
    //
    // 这个方案的问题是，当数据量很大，而相同桶位的元素很少时，会造成大量的空间浪费
    //
    // bucket *buckets[numsSize + 1][numsSize + 1];
    // for (int i = 0; i < numsSize + 1; ++i) {
    //     for (int j = 0; j < numsSize + 1; ++j) {
    //         buckets[i][j] = NULL;
    //     }
    // }

    // 最终方案：
    //
    // 排序桶是一个一维数组，当另外一个元素也在此桶位时，通过类似链表的方式连接起来
    // 0 => a -> b -> NULL
    // 1 => c -> d -> NULL
    //      ^
    //   插入新数据位置

    typedef struct _element {
        bucket *val;
        struct _element *next;
    } element;

    element *buckets[numsSize + 1];

    for (int i = 0; i < numsSize + 1; ++i) {
        buckets[i] = NULL;
    }

    hash_iterator *hi = hash_iterator_init(hm);

    // 遍历map来往桶中插入数据
    while (hash_iterator_next(hi)) {
        bucket *bk = hash_iterator_cur(hi);
        int frq = (int) hash_map_get_uint_value(bk);

        // 相同桶位的插入在链表最前面
        element *el = malloc(sizeof(element));
        el->val = bk;
        el->next = buckets[frq];

        buckets[frq] = el;

    }

    // 倒序遍历桶，获取k个元素作为返回值
    int *ret = malloc(k * sizeof(int));
    int t = 0;

    for (int i = numsSize; i >= 0; --i) {
        element *ref = buckets[i];
        while (ref) {
            if (t == k) {
                goto STOP;
            }

            ret[t++] = hash_map_get_uint_key(ref->val);
            ref = ref->next;
        }
    }

    STOP:

    *returnSize = t;
    hash_map_destroy(hm);

    return ret;
}

