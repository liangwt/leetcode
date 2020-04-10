#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        string t = "";
        vector<string> sk;

        for (auto const &ss : s)
        {
            if (ss != ' ')
            {
                t.push_back(ss);
            }
            else
            {
                if (t != "")
                {
                    sk.push_back(t);
                    t = "";
                }
            }
        }

        if (t != "")
        {
            sk.push_back(t);
            t = "";
        }

        string ans = "";
        for (int i = sk.size() - 1; i >= 0; i--)
        {
            ans.append(sk[i]);
            ans.push_back(' ');
        }

        if (ans != "")
        {
            ans.pop_back();
        }

        return ans;
    }
};

int main()
{
    Solution s;
    assert(s.reverseWords("") == "");
    assert(s.reverseWords("    ") == "");
    assert(s.reverseWords("the sky is blue") == "blue is sky the");
    assert(s.reverseWords("  hello world!  ") == "world! hello");
    assert(s.reverseWords("a good   example") == "example good a");
}