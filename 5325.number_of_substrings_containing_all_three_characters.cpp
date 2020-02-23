#include <string>
#include <assert.h>

using namespace std;

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int ra = -1, rb = -1, rc = -1, total = 0;
        for (int i = 0; i < s.size(); i++)
        {
            // 更新 abc字符的位置
            if (s[i] == 'a')
            {
                ra = i;
            }
            if (s[i] == 'b')
            {
                rb = i;
            }
            if (s[i] == 'c')
            {
                rc = i;
            }

            // 获取当前子串的最左端
            int l = min(min(ra, rb), rc);

            // 不满足条件继续往右增长
            if (l == -1)
                continue;

            // 满足条件，l就是子串的最左端
            // 满足条件的数量就是往前的数量
            total += (l + 1);
        }

        return total;
    }
};

int main()
{
    Solution s;
    assert(s.numberOfSubstrings("abcabc") == 10);
    assert(s.numberOfSubstrings("aaacb") == 3);
    assert(s.numberOfSubstrings("abc") == 1);
}