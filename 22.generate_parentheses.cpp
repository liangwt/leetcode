#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    vector<string> ans;
public:
    vector<string> generateParenthesis(int n) {
        ans = {};
        string str = "";
        helper(str, n, n);
        return ans;
    }

    void helper(string &str, int left_num, int right_num){
        
        if(left_num < 0 || right_num < 0 || left_num > right_num){
            return;
        }

        if(left_num == 0 && right_num == 0){
            ans.push_back(str);
        }

        str.push_back('(');
        helper(str, left_num-1, right_num);
        str.pop_back();
        
        str.push_back(')');
        helper(str, left_num, right_num-1);
        str.pop_back();
        
    }
};

int main() {
    Solution s;

    vector<string> r1 = {
        "((()))",
        "(()())",
        "(())()",
        "()(())",
        "()()()",
    };
    assert(s.generateParenthesis(3) == r1);

    vector<string> r2 = {""};
    assert(s.generateParenthesis(0) == r2);

    vector<string> r3 = {"()"};
    assert(s.generateParenthesis(1) == r3);

    return 0;
}