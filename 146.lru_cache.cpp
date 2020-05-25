/**
 * Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.
 * 
 * get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
 * 
 * The cache is initialized with a positive capacity.
 * 
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 * 
 * Example:
 * 
 * LRUCache cache = new LRUCache( 2 );
 * 
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // returns 1
 * cache.put(3, 3);    // evicts key 2
 * cache.get(2);       // returns -1 (not found)
 * cache.put(4, 4);    // evicts key 1
 * cache.get(1);       // returns -1 (not found)
 * cache.get(3);       // returns 3
 * cache.get(4);       // returns 4
 * 
 */

/**
 * 主要使用两个数据结构来存储数据
 *
 * list 用来储存key, value的键值对，当新增、更新、查询相应的操作时，除了必要的操作之外，需要把查询到的节点移动到链表的头部
 *      对于移动链表中的节点，可以使用splice()函数，它可以把一个链表中的某个元素，移动到另一个链表上。
 *
 * map  的key是保存的key，value是在链表中的iterator
 *
 * 所以对于put来说
 *
 * 1. 首先在map中查询是否存在，如果存在则执行更新操作，同时把节点移动到链表头部
 * 2. 如果不存在，则需要新增元素，先判断是否达到容量上限，如果达到容量上限则，则需要移除链表尾部的元素，同时在map中移除此元素
 *   对于新增的元素直接插入到链表头部。同时插入map中，在map中的值为链表头部的iterator
 *
 * 对于get来说
 *
 * 1. 根据map来查找iterator，如果不存在则返回-1
 * 2. 根据iterator来获取到应该返回的值，在返回之前需要把此元素移动到链表头部
 */

#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
private:
    int capacity;
    unordered_map<int, list<pair<int, int>>::iterator> M;
    list<pair<int, int>> L;

    inline void refresh(list<pair<int, int>>::iterator &idx) {
        // transfers only the element pointed by i from x into the container.
        if (idx != L.begin()) {
            L.splice(L.begin(), L, idx);
        }
    }

    inline void evicts() {
        if (L.size() >= capacity) {
            auto r = L.back();
            M.erase(r.first);
            L.pop_back();
        }
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        auto idx = M.find(key);
        if (idx == M.end()) {
            return -1;
        }

        refresh(idx->second);

        return idx->second->second;
    }

    void put(int key, int value) {
        auto idx = M.find(key);
        // 不存在则新增
        if (idx == M.end()) {
            // 超过容量限制则移除旧元素
            evicts();

            L.push_front({key, value});
            M[key] = L.begin();
            return;
        }

        // 已经存在进行修改并移动到链表最前端
        *(idx->second) = {key, value};
        refresh(idx->second);
    }
};

int main() {
    auto *c1 = new LRUCache(2);
    c1->put(1, 1);
    c1->put(2, 2);
    assert(c1->get(1) == 1);    // returns 1
    c1->put(3, 3);              // evicts key 2
    assert(c1->get(2) == -1);   // returns -1 (not found)
    c1->put(4, 4);              // evicts key 1
    assert(c1->get(1) == -1);   // returns -1 (not found)
    assert(c1->get(3) == 3);    // returns 3
    assert(c1->get(4) == 4);    // returns 4

    auto *c2 = new LRUCache(2);
    c2->put(2, 1);
    c2->put(1, 1);
    c2->put(2, 3);
    c2->put(4, 1);
    assert(c2->get(1) == -1);
    assert(c2->get(2) == 3);
}