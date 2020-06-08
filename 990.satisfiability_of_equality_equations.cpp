#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class UF
{
private:
    unordered_map<int, int> table;

public:
    UF()
    {
        table = {};
    }

    void make(int x)
    {
        table[x] = x;
    }

    int find(int x)
    {
        int root = x;

        while (table[root] != root)
        {
            root = table[root];
        }

        if (root == 0)
        {
            table[x] = x;
            return x;
        }

        return root;
    }

    bool merge(int x, int y)
    {
        int i = find(x), j = find(y);

        if (i == j)
        {
            return false;
        }

        table[i] = j;
        return true;
    }

    bool connected(int x, int y)
    {
        return find(x) == find(y);
    }
};

class Solution
{
public:
    bool equationsPossible(vector<string> &equations)
    {
        UF uf;

        for (const auto &e : equations)
        {
            char x = e.substr(0, 1)[0];
            string r = e.substr(1, 2);
            char y = e.substr(3, 1)[0];

            if (r == "==")
            {
                uf.merge(x, y);
            }
        }

        for (const auto &e : equations)
        {
            char x = e.substr(0, 1)[0];
            string r = e.substr(1, 2);
            char y = e.substr(3, 1)[0];

            if (r == "!=")
            {
                if (uf.connected(x, y))
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution s;

    vector<string> e1 = {"a==b", "b!=a"};
    assert(s.equationsPossible(e1) == false);

    vector<string> e2 = {"b==a", "a==b"};
    assert(s.equationsPossible(e2) == true);

    vector<string> e3 = {"a==b", "b==c", "a==c"};
    assert(s.equationsPossible(e3) == true);

    vector<string> e4 = {"a==b", "b!=c", "c==a"};
    assert(s.equationsPossible(e4) == false);

    vector<string> e5 = {"c==c", "b==d", "x!=z"};
    assert(s.equationsPossible(e5) == true);
}