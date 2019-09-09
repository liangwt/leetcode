/*
 * You have an array of logs.  Each log is a space delimited string of words.
 *
 * For each log, the first word in each log is an alphanumeric identifier.  Then, either:
 *
 * Each word after the identifier will consist only of lowercase letters, or;
 * Each word after the identifier will consist only of digits.
 * We will call these two varieties of logs letter-logs and digit-logs.  It is guaranteed that each log has at least one word after its identifier.
 *
 * Reorder the logs so that all of the letter-logs come before any digit-log.  The letter-logs are ordered lexicographically ignoring identifier, with the identifier used in case of ties.  The digit-logs should be put in their original order.
 *
 * Return the final order of the logs.
 *
 *
 *
 * Example 1:
 *
 * Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
 * Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]
 *
 *
 * Constraints:
 *
 * 0 <= logs.length <= 100
 * 3 <= logs[i].length <= 100
 * logs[i] is guaranteed to have an identifier, and a word after the identifier.
 */

/**
 * c++ 标准库排序 sort()
 *
 * vector拼接使用insert()
 */

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> reorderLogFiles(vector<string> &logs) {
        vector<string> letter_logs;
        vector<string> digit_logs;

        for (auto &log:logs) {
            string s = log.substr(log.find(' ') + 1, 1);
            if (isalpha(s[0])) {
                letter_logs.push_back(log);
            } else {
                digit_logs.push_back(log);
            }
        }

        auto cmp = [](string x, string y) -> bool {
            string xx = x.substr(x.find(' '));
            string yy = y.substr(y.find(' '));

            if (xx == yy) {
                return x < y;
            }

            return xx < yy;
        };

        sort(letter_logs.begin(), letter_logs.end(), cmp);

        letter_logs.insert(letter_logs.end(), digit_logs.begin(), digit_logs.end());

        return letter_logs;
    }
};

int main() {
    Solution s;

    vector<string> l1 = {"dig1 8 1 5 1", "let1 art can", "dig2 3 6", "let2 own kit dig", "let3 art zero"};
    vector<string> r1 = {"let1 art can", "let3 art zero", "let2 own kit dig", "dig1 8 1 5 1", "dig2 3 6"};
    assert(s.reorderLogFiles(l1) == r1);

    vector<string> l2 = {};
    vector<string> r2 = {};
    assert(s.reorderLogFiles(l2) == r2);

    return 0;
}