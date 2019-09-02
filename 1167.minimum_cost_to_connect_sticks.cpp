/**
 * You have some sticks with positive integer lengths.
 *
 * You can connect any two sticks of lengths X and Y into one stick by paying a cost of X + Y.  You perform this action until there is one stick remaining.
 *
 * Return the minimum cost of connecting all the given sticks into one stick in this way.
 *
 *
 *
 * Example 1:
 *
 * Input: sticks = [2,4,3]
 * Output: 14
 * Example 2:
 *
 * Input: sticks = [1,8,3,5]
 * Output: 30
 *
 *
 * Constraints:
 *
 * 1 <= sticks.length <= 10^4
 * 1 <= sticks[i] <= 10^4
 */

/**
 * 在每次合并时都选择最短的两根
 *
 * 例如 2, 2, 3, 3
 *
 * 第一次合并 2, 2 得到：4, 3, 3 消耗：4
 * 第二次合并 3, 3 得到：4, 6    消耗：6
 * 第三次合并 4, 6 得到：10      消耗: 10
 * 总消耗 4+6+10 = 20
 *
 *
 * 所以重点在于每次合并时选择当前所有长度里最短的两个
 *
 * 需要注意的是，在第一次排序之后按顺序合并是不正确的
 * 上面的示例中就不是按最初的排序来合并的
 *
 * 所有使用优先队列，每次取出前两个最小值，然后把合并出来的新长度加回到队列中
 * 当队列中只剩下一个元素时，则说明被合并完成
 */

#include <vector>
#include <queue>
#include <assert.h>

using namespace std;

class Solution {
public:
    int connectSticks(vector<int> sticks) {
        priority_queue<int, vector<int>, greater<int>> pri;
        int ret = 0;

        for (auto stick : sticks) {
            pri.push(stick);
        }

        while (pri.size() > 1) {
            int t1 = pri.top();
            pri.pop();

            int t2 = pri.top();
            pri.pop();

            ret = ret + t1 + t2;
            pri.push(t1 + t2);
        }

        return ret;
    }
};


int main() {
    Solution s;

    vector<int> s1 = {2, 4, 3};
    assert(s.connectSticks(s1) == 14);

    vector<int> s2 = {1, 8, 3, 5};
    assert(s.connectSticks(s2) == 30);

    vector<int> s3 = {8, 4, 6, 12};
    assert(s.connectSticks(s3) == 58);

    vector<int> s4 = {20, 4, 8, 2};
    assert(s.connectSticks(s4) == 54);

    vector<int> s5 = {1, 2, 5, 10, 35, 89};
    assert(s.connectSticks(s5) == 224);

    vector<int> s6 = {2, 2, 3, 3};
    assert(s.connectSticks(s6) == 20);

    return 0;
}