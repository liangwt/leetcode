/*
 * Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks. Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.
 *
 * However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.
 *
 * You need to return the least number of intervals the CPU will take to finish all the given tasks.
 *
 *
 *
 * Example:
 *
 * Input: tasks = ["A","A","A","B","B","B"], n = 2
 * Output: 8
 * Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
 *
 *
 * Note:
 *
 * The number of tasks is in the range [1, 10000].
 * The integer n is in the range [0, 100].
 *
 */

/**
 * 首先理解题意：
 *   其中n是指相同任务的间隔
 *   例如n=2 那A和A直接必须得隔两个空位 AXXA， 这个X可以是其他任务，也可以是idle。
 *   如果是ABCABC依旧是符合要求的，因为A与A间隔超过了2，B与B间隔也超过了2
 *
 * 解题思路：
 *
 *   我们找到数量最多的任务，然后再根据n值在任务中插入空，之后用剩余的任务填充这些空值，最后得到的长度就是需要的周期，空值就是idle
 *
 *   再思考如何获取最终结果的长度，对于数量最多的任务个数mx。因为是现在任务之间插入空值，所以长度的一部分为 (mx-1)*(n+1)
 *   这部分没有包含最后的结尾，最后结尾的长度应该是具有相同最多数量的任务的个数num
 *
 *   例如 ['A', 'A', 'A', 'B', 'B'] , 2
 *
 *   任务A的数量最多，在A之间直接插入数量为n的空，可得
 *
 *   A--A--A
 *
 *   然后用剩余的B来填充，得
 *
 *   AB-AB-A
 *
 *   而所需时间就是 A的个数3-1，乘上n+1得 6 这是 `AB-AB-` 的长度，再加上末尾的A就是总长度7
 *
 *
 *   例如 {'A', 'A', 'A', 'B', 'B', 'B', 'C'}, 2
 *
 *   任务 A、B数量最多，数量都是num = 2，在AB之间插入n-1个空值
 *
 *   AB-AB-AB
 *
 *   剩余用C来填充
 *
 *   ABCAB-AB
 *
 *   所需时间为：A的个数3-1，乘上n+1 得 6，这是 `ABCAB-`的长度，再加上末尾AB，注意是AB的长度2
 *
 */

#include <vector>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char> &tasks, int n) {
        vector<int> table(25, 0);
        for (auto task : tasks) {
            table[task - 'A']++;
        }

        int mx = 0, nu = 0;
        for (auto i: table) {
            if (i == mx) {
                nu++;
            }
            if (i > mx) {
                mx = i;
                nu = 1;
            }
        }

        return max((int) tasks.size(), (mx - 1) * (n + 1) + nu);
    }
};

int main() {
    Solution s;

    vector<char> t1 = {'A', 'A', 'A', 'B', 'B', 'B'};
    assert(s.leastInterval(t1, 2) == 8);

    vector<char> t2 = {'A', 'B', 'C', 'D', 'E', 'A', 'B', 'C', 'D', 'E'};
    assert(s.leastInterval(t2, 4) == 10);

    vector<char> t3 = {'A', 'A', 'A', 'A', 'B', 'B', 'B', 'C', 'C'};
    assert(s.leastInterval(t3, 2) == 10);

    vector<char> t4 = {'A', 'A', 'A', 'B', 'B', 'B'};
    assert(s.leastInterval(t4, 0) == 6);

    return 0;
}

