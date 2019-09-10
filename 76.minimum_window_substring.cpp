/**
 * Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
 *
 * Example:
 *
 * Input: S = "ADOBECODEBANC", T = "ABC"
 * Output: "BANC"
 * Note:
 *
 * If there is no such window in S that covers all characters in T, return the empty string "".
 * If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
 */

#include <string>
#include <unordered_map>

#include <limits.h>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> _table;

        for (auto tt : t) {
            _table[tt]++;
        }

        int cnt = 0, left = 0, mn = INT_MAX, result = -1;

        for (int i = 0; i < s.size(); i++) {
            if (--_table[s[i]] >= 0) {
                cnt++;

                while (cnt >= t.size()) {
                    if (++_table[s[left]] > 0) {
                        if (i - left + 1 < mn) {
                            result = left;
                            mn = i - left + 1;
                        }
                        cnt--;
                    }
                    left++;
                }
            }
        }

        return  result == -1 ? "" : s.substr(result, mn);
    }
};

int main() {
    Solution s;

    assert(s.minWindow("ADOBECODEBANC", "ABC") == "BANC");
    assert(s.minWindow("AAAAAAAAAAABC", "ABC") == "ABC");
    assert(s.minWindow("NC", "ABC") == "");
    assert(s.minWindow("NC", "") == "");
    assert(s.minWindow("", "ABC") == "");

    return 0;
}