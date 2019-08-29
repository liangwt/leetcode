/**
 * Given a list accounts, each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.
 *
 * Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some email that is common to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.
 *
 * After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.
 *
 * Example 1:
 * Input:
 * accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
 * Output: [["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
 * Explanation:
 * The first and third John's are the same person as they have the common email "johnsmith@mail.com".
 * The second John and Mary are different people as none of their email addresses are used by other accounts.
 * We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'],
 * ['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
 * Note:
 *
 * The length of accounts will be in the range [1, 1000].
 * The length of accounts[i] will be in the range [1, 10].
 * The length of accounts[i][j] will be in the range [1, 30].
 */

/**
 * 使用并交集
 *
 * 首先需要一个map来记录每一个邮箱归属的账号
 *
 * johnsmith@mail.com => John
 * john00@mail.com    => John
 * mary@mail.com      => Mary
 *
 * 之后遍历所以账号，用每个账号的第一个邮箱去检查是否在集合中，没有则创建。
 * 于是获取到此邮箱所在集合，把这个账号下的剩余的邮箱都加到这个集合中
 *
 * 用之前的map来遍历所有账号，并把在同一个集合(集合的代表相同）的账号放到一个数组中，此步还是用map来做
 *
 * johnsmith@mail.com   => [johnsmith@mail.com, john00@mail.com, john_newyork@mail.com]
 * johnnybravo@mail.com => [johnnybravo@mail.com]
 * mary@mail.com        => [mary@mail.com]
 *
 * 根据最初开始的map来把根邮箱对应的账号放到数组第一个位置，得到最终结果
 *
 * johnsmith@mail.com   => [John, johnsmith@mail.com, john00@mail.com, john_newyork@mail.com]
 * johnnybravo@mail.com => [John, johnnybravo@mail.com]
 * mary@mail.com        => [Mary, mary@mail.com]
 *
 */

#include <vector>
#include <string>
#include <unordered_map>

#include <assert.h>

using namespace std;

class UF {
private:
    unordered_map<string, string> _table;
    unordered_map<string, int> _rank;
public:

    void make(string x) {
        _table[x] = x;
        _rank[x] = 0;
    }

    string find(string x) {
        while (x != _table[x]) {
            x = _table[x];
        }

        return x;
    }

    bool merge(const string &x, const string &y) {
        string i = find(x);
        if (i.empty()) {
            make(x);
            i = x;
        }

        string j = find(y);
        if (j.empty()) {
            make(y);
            j = y;
        }

        if (i == j) {
            return false;
        }

        if (_rank[i] > _rank[j]) {
            _table[j] = i;
            _rank[i] += _rank[j];
        } else {
            _table[j] = i;
            _rank[j] += _rank[i];
        }


        return true;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        unordered_map<string, string> acc;
        acc.reserve(accounts.size());

        UF uf;

        for (auto account : accounts) {
            acc[account[1]] = account[0];

            string root = uf.find(account[1]);
            if (root.empty()) {
                uf.make(account[1]);
                root = account[1];
            }

            for (int i = 2; i < account.size(); i++) {
                // 记录邮箱归属账号
                acc[account[i]] = account[0];

                // 合并到集合
                uf.merge(root, account[i]);
            }
        }

        unordered_map<string, vector<string>> p;
        for (auto &a: acc) {
            if (!a.first.empty()) {
                p[uf.find(a.first)].push_back(a.first);
            }
        }

        vector<vector<string>> ret;
        for (auto &line: p) {
            vector<string> v(line.second.begin(), line.second.end());
            v.insert(v.begin(), acc[line.first]);

            sort(v.begin() + 1, v.end());
            ret.push_back(v);
        }

        return ret;
    }
};

int main() {
    auto equal = [](vector<vector<string>> x, vector<vector<string>> y) -> bool {
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        for (int i = 0; i < x.size(); i++) {
            if (x[i] != y[i]) {
                return false;
            }
        }

        return true;
    };

    Solution s;

    vector<vector<string>> acc1 = {
        {"John", "johnsmith@mail.com", "john00@mail.com"},
        {"John", "johnnybravo@mail.com"},
        {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
        {"Mary", "mary@mail.com"},
    };

    vector<vector<string>> out1 = {
        {"John", "john00@mail.com", "john_newyork@mail.com", "johnsmith@mail.com"},
        {"John", "johnnybravo@mail.com"},
        {"Mary", "mary@mail.com"},
    };

    assert(equal(s.accountsMerge(acc1), out1));

    vector<vector<string>> acc2 = {};

    vector<vector<string>> out2 = {};

    assert(s.accountsMerge(acc2) == out2);

    return 0;

};