#include <string>
#include <vector>
#include <assert.h>

using namespace std;

class Solution
{
public:
    vector<int> maxDepthAfterSplit(string seq)
    {
        int num_a = 0, num_b = 0;
        vector<int> ans;

        for (int i = 0; i < seq.size(); ++i)
        {
            if (seq[i] == '(')
            {
                if (num_a <= num_b)
                {
                    num_a++;
                    ans.push_back(0);
                }
                else
                {
                    num_b++;
                    ans.push_back(1);
                }
            }
            else
            {
                if (num_a > num_b)
                {
                    num_a--;
                    ans.push_back(0);
                }
                else
                {
                    num_b--;
                    ans.push_back(1);
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;

    auto ans1 = vector<int>{0, 1, 1, 1, 1, 0};
    assert(s.maxDepthAfterSplit("(()())") == ans1);

    auto ans2 = vector<int>{0, 0, 0, 1, 1, 0, 0, 0};
    assert(s.maxDepthAfterSplit("()(())()") == ans2);
}