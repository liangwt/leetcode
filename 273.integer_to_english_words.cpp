/**
 * Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.
 *
 * Example 1:
 *
 * Input: 123
 * Output: "One Hundred Twenty Three"
 * Example 2:
 *
 * Input: 12345
 * Output: "Twelve Thousand Three Hundred Forty Five"
 * Example 3:
 *
 * Input: 1234567
 * Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
 * Example 4:
 *
 * Input: 1234567891
 * Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"
 */

/**
 * 每三位一算，对于小于20的数还得单独处理，额外还需要处理好空格，没啥好办法，多写些test case慢慢改
 */

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    vector<string> _bits = {
        "",
        "Thousand",
        "Million",
        "Billion",
    };

    unordered_map<int, string> _table = {
        {0,  "Zero"},
        {1,  "One"},
        {2,  "Two"},
        {3,  "Three"},
        {4,  "Four"},
        {5,  "Five"},
        {6,  "Six"},
        {7,  "Seven"},
        {8,  "Eight"},
        {9,  "Nine"},
        {10, "Ten"},
        {11, "Eleven"},
        {12, "Twelve"},
        {13, "Thirteen"},
        {14, "Fourteen"},
        {15, "Fifteen"},
        {16, "Sixteen"},
        {17, "Seventeen"},
        {18, "Eighteen"},
        {19, "Nineteen"},
        {20, "Twenty"},
        {30, "Thirty"},
        {40, "Forty"},
        {50, "Fifty"},
        {60, "Sixty"},
        {70, "Seventy"},
        {80, "Eighty"},
        {90, "Ninety"},
    };
public:
    string numberToWords(int num) {
        if (num == 0) {
            return _table[num];
        }

        string result;

        int n = num;
        int l = num;
        int i = -1;

        while (l > 0) {
            string temp;

            n = l % 1000;
            l = l / 1000;
            i++;

            if (n >= 100) {
                temp.append(hundredBuild(n));
            } else {
                temp.append(littleBuild(n));
            }

            if (n != 0) {
                temp.push_back(' ');
                temp.append(_bits[i]);
                temp.push_back(' ');
            }

            result.insert(result.begin(), temp.begin(), temp.end());
        }

        return result.erase(result.find_last_not_of(' ') + 1);
    }

    inline string hundredBuild(int num) {
        string temp;
        int hundred = num / 100;
        int hundred_mod = num % 100;

        temp.append(_table[hundred]);
        temp.push_back(' ');
        temp.append("Hundred");

        if (hundred_mod != 0) {
            temp.push_back(' ');
            temp.append(littleBuild(hundred_mod));
        }

        return temp;
    }

    inline string littleBuild(int num) {

        string temp;

        if (num > 20) {
            int tens = num / 10 * 10;
            int bits = num % 10;

            temp.append(_table[tens]);

            if (bits != 0) {
                temp.push_back(' ');
                temp.append(_table[bits]);
            }

        } else if (num > 0) {
            temp.append(_table[num]);
        }

        return temp;
    }

};

int main() {
    Solution s;

    assert(s.numberToWords(0) == "Zero");
    assert(s.numberToWords(1) == "One");
    assert(s.numberToWords(12) == "Twelve");
    assert(s.numberToWords(30) == "Thirty");
    assert(s.numberToWords(123) == "One Hundred Twenty Three");
    assert(s.numberToWords(1000) == "One Thousand");
    assert(s.numberToWords(12345) == "Twelve Thousand Three Hundred Forty Five");
    assert(s.numberToWords(50868) == "Fifty Thousand Eight Hundred Sixty Eight");
    assert(s.numberToWords(1000000) == "One Million");
    assert(s.numberToWords(1234567) == "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven");
    assert(s.numberToWords(1000000000) == "One Billion");
    assert(s.numberToWords(1234567891) ==
           "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One");

    return 0;
}