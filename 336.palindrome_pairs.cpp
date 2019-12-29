/**
 * Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.
 *
 * Example 1:
 *
 * Input: ["abcd","dcba","lls","s","sssll"]
 * Output: [[0,1],[1,0],[3,2],[2,4]]
 * Explanation: The palindromes are ["dcbaabcd","abcddcba","slls","llssssll"]
 * Example 2:
 *
 * Input: ["bat","tab","cat"]
 * Output: [[0,1],[1,0]]
 * Explanation: The palindromes are ["battab","tabbat"]
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector <vector<int>> palindromePairs(vector <string> &words) {

    }
};

int main() {
    Solution s;

    vector <string> w1 = {"abcd", "dcba", "lls", "s", "sssll"};
    vector <vector<int>> r1 = {
        {0, 1},
        {1, 0},
        {3, 2},
        {2, 4},
    };
    assert(s.palindromePairs(w1) == r1);

    vector <string> w2 = {"bat", "tab", "cat"};
    vector <vector<int>> r2 = {
        {0, 1},
        {1, 0},
    };
    assert(s.palindromePairs(w2) == r2);

    return 0;
}