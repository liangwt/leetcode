/**
 * Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.
 *
 * Example 1:
 *
 * Input: [[0, 30],[5, 10],[15, 20]]
 * Output: 2
 * Example 2:
 *
 * Input: [[7,10],[2,4]]
 * Output: 1
 * NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.
 */

/**
 * 思路一：
 *
 *  把输入到所有时间对的起止时间平铺到一条线上，从头开始遍历这条线。
 *  当遇到一个开始时间，说明房间数得新增一个
 *  当遇到一个结束时间，说明一个房间被使用完成，房间数减一
 *  在这个过程中，记录下房间最多的值即返回的结果
 *
 *  在c++中使用TreeMap把开始时间递增，把结束时间递减。因为TreeMap会按照键值排好序，所以在遍历的过程中房间数就是不断的加上map的值
 *
 *  代码如下
 *
 *  ```c++
 *  class Solution {
 *  public:
 *      int minMeetingRooms(vector<vector<int>> &intervals) {
 *          map<int, int> _table;
 *
 *          for (auto interval : intervals) {
 *              _table[interval[0]]++;
 *              _table[interval[1]]--;
 *          }
 *
 *          int result = 0, mx = 0;
 *
 *          for (auto it: _table) {
 *              mx += it.second;
 *              result = max(result, mx);
 *          }
 *
 *          return result;
 *      }
 *  };
 *  ```
 *
 *  思路二：使用最小堆
 *
 *  先按照开始时间把时间对进行排序
 *
 *  之后逐个遍历每一对起止时间，
 *  当堆为空或者堆顶元素大于当前时间对的开始时间时，说明还没有房间或者上一个房间还没结束，需要新加一个房间，所以把结束时间加入到堆中。
 *  当堆顶元素小于当前时间对的开始时间时，说明已经有一个房间结束了可以拿来用，所以弹出这个时间，把当前的结束时间加入到堆中
 *
 */

#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> x, vector<int> y) -> bool { return x[0] < y[0]; });

        priority_queue<int, vector<int>, greater<int>> pri;

        for (auto interval : intervals) {
            if (!pri.empty() && pri.top() < interval[0]) {
                pri.pop();
            }

            pri.push(interval[1]);
        }

        return (int) pri.size();
    }
};

int main() {
    Solution s;

    vector<vector<int>> i1 = {
        {0,  30},
        {5,  10},
        {15, 20},
    };
    assert(s.minMeetingRooms(i1) == 2);

    vector<vector<int>> i2 = {
        {7, 10},
        {2, 4},
    };
    assert(s.minMeetingRooms(i2) == 1);

    vector<vector<int>> i3 = {};
    assert(s.minMeetingRooms(i3) == 0);

    vector<vector<int>> i4 = {
        {0,  9},
        {5,  11},
        {10, 20},
    };
    assert(s.minMeetingRooms(i4) == 2);
}