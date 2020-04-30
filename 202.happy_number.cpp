/**
 * Write an algorithm to determine if a number is "happy".
 * 
 * A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
 * 
 * Example: 
 * 
 * Input: 19
 * Output: true
 * Explanation: 
 * 12 + 92 = 82
 * 82 + 22 = 68
 * 62 + 82 = 100
 * 12 + 02 + 02 = 1
 */

/**
 * 对于不是happy number的数字，最后sum一定会是一个循环
 * 所以使用一个cache的集合来记录已经出现过的sum
 * 
 * 在不断求解每一位的平方和的同时记录到cache集合中
 * 如果某一次的平方和已经在集合中了，则说明此数不是happy number
 */

#include <assert.h>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> cache;

        while (n != 1)
        {
            int a, t = 0, i = n;

            while (n)
            {
                a = n % 10;
                t += (a * a);
                n = n / 10;
            }

            if (cache.find(t) != cache.end())
            {
                return false;
            }

            cache.insert(i);
            n = t;
        }

        return true;
    }
};

int main()
{
    Solution s;

    assert(s.isHappy(19) == true);
    assert(s.isHappy(1111111) == true);
    assert(s.isHappy(20) == false);
    assert(s.isHappy(0) == false);

    return 0;
}