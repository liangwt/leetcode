#include <vector>
#include <string>
#include <unordered_map>
#include <assert.h>

#include <iostream>

using namespace std;

class Solution
{
public:
    int minimumLengthEncoding(vector<string> &words)
    {
        sort(words.begin(), words.end(), [](string a, string b) -> bool {
            return a.size() > b.size();
        });

        unordered_map<string, bool> table;
        int ans = 0;

        for (const auto &word : words)
        {
            if (table[word])
            {
                continue;
            }

            int len = word.size();

            ans += (len + 1);

            for (auto iter = word.begin(); iter != word.end(); iter++)
            {
                string t = string(iter, word.end());
                table[t] = true;
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;

    vector<string> w1 = {"time", "me", "bell"};
    assert(s.minimumLengthEncoding(w1) == 10);

    vector<string> w2 = {};
    assert(s.minimumLengthEncoding(w2) == 0);
}