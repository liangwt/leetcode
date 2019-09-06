/**
 * Design a data structure that supports all following operations in average O(1) time.
 * 
 * insert(val): Inserts an item val to the set if not already present.
 * remove(val): Removes an item val from the set if present.
 * getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
 * Example:
 * 
 * // Init an empty set.
 * RandomizedSet randomSet = new RandomizedSet();
 * 
 * // Inserts 1 to the set. Returns true as 1 was inserted successfully.
 * randomSet.insert(1);
 * 
 * // Returns false as 2 does not exist in the set.
 * randomSet.remove(2);
 * 
 * // Inserts 2 to the set, returns true. Set now contains [1,2].
 * randomSet.insert(2);
 * 
 * // getRandom should return either 1 or 2 randomly.
 * randomSet.getRandom();
 * 
 * // Removes 1 from the set, returns true. Set now contains [2].
 * randomSet.remove(1);
 * 
 * // 2 was already in the set, so return false.
 * randomSet.insert(2);
 * 
 * // Since 2 is the only number in the set, getRandom always return 2.
 * randomSet.getRandom();
 */

/**
 * 使用map和数组两个数据结构来存储数据
 *
 * 插入：
 *  1. 通过map查找是否存在，如果存在返回false          ....O(1)
 *  2. 把val插入到数组最后一位                        ....O(1)
 *  3. 把val插入到map中key是val，value是在数组中的位置 ....O(1)
 *
 * 删除：
 *  1. 通过map查找是否存在，如果不存在返回false                 ....O(1)
 *  2. 根据在map查找的value，把数组的最后一位和这一位置进行交换   ....O(1)
 *  3. 更新数组最后一位在map中的value                          ....O(1)
 *  4. 删除数组最后一位                                       ....O(1)
 *  5. 删除map中的值                                         ....O(1)
 *
 * 获取随机值
 *
 *  1. 生成一个0到数组大小的随机数
 *  2. 返回数组中的对于位置的值
 */

#include <unordered_map>
#include <vector>

using namespace std;

class RandomizedSet {
private:
    unordered_map<int, int> _set;
    vector<int> _vec;

public:
    /** Initialize your data structure here. */
    RandomizedSet() {}

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        auto i = _set.find(val);

        if (i == _set.end()) {
            _vec.push_back(val);
            _set[val] = (int)_vec.size() - 1;
            return true;
        }

        return false;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto i = _set.find(val);
        if (i == _set.end()) {
            return false;
        }

        _set[_vec.back()] = i->second;
        _vec[i->second] = _vec.back();

        _vec.pop_back();

        _set.erase(i);
        return true;

    }

    /** Get a random element from the set. */
    int getRandom() {
        return _vec[rand() % _vec.size()];
    }
};

int main() {
    RandomizedSet obj;
    assert(obj.insert(1));
    assert(!obj.remove(2));
    assert(obj.insert(2));
    assert(obj.getRandom() == 2 || obj.getRandom() == 1);
    assert(obj.getRandom() == 2 || obj.getRandom() == 1);
    assert(obj.remove(1));
    assert(!obj.insert(2));
    assert(obj.getRandom() == 2);
}