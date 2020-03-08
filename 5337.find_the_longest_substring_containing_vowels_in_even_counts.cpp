#include <string>
#include <vector>
#include <assert.h>

using namespace std;

class Solution
{
public:
    int findTheLongestSubstring(string s)
    {
        vector<int> states = vector<int>(32, INT_MAX);
        states[0] = -1; // 状态零是空字符串

        int state = 0, result = 0;

        for (int i = 0; i < s.size(); i++)
        {
            switch (s[i])
            {
            case 'a':
                state ^= 1;
                break;
            case 'e':
                state ^= 2;
                break;
            case 'i':
                state ^= 4;
                break;
            case 'o':
                state ^= 8;
                break;
            case 'u':
                state ^= 16;
                break;
            default:
                break;
            }

            if(states[state] == INT_MAX){
                states[state] = i;
            }else{
                result = max(result,i - states[state]);
            }
        }

        return result;
    }
};

int main()
{
    Solution s;
    assert(s.findTheLongestSubstring("eleetminicoworoep") == 13);
    assert(s.findTheLongestSubstring("leetcodeisgreat") == 5);
    assert(s.findTheLongestSubstring("bcbcbc") == 6);
}

