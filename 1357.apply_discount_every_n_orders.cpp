#include <unordered_map>
#include <vector>
#include <assert.h>

using namespace std;

class Cashier
{
private:
    int n;
    int discount;

    unordered_map<int, int> _table;
    int cal_num = 1;

public:
    Cashier(int n, int discount, vector<int> &products, vector<int> &prices)
    {
        this->n = n;
        this->discount = discount;

        for (int i = 0; i < products.size(); i++)
        {
            this->_table[products[i]] = prices[i];
        }
    }

    double getBill(vector<int> product, vector<int> amount)
    {
        // 计算实际价格
        double total = 0;
        for (int i = 0; i < product.size(); i++)
        {
            total += _table[product[i]] * amount[i];
        }

        if (cal_num == n)
        {
            cal_num = 1;
            return total * (1 - discount / 100.0);
        }
        cal_num++;
        return total;
    }
};

int main()
{
    vector<int> products = {1, 2, 3, 4, 5, 6, 7};
    vector<int> prices = {100, 200, 300, 400, 300, 200, 100};
    Cashier cashier(3, 50, products, prices);

    // 返回 500.0, 账单金额为 = 1 * 100 + 2 * 200 = 500.
    assert((cashier.getBill({1, 2}, {1, 2}) - 500.0) < 0.00001);
    // 返回 4000.0
    assert((cashier.getBill({3, 7}, {10, 10}) - 4000.0) < 0.00001);
    // 返回 800.0 ，账单原本为 1600.0 ，但由于该顾客是第三位顾客，他将得到 50% 的折扣，所以实际金额为 1600 - 1600 * (50 / 100) = 800 。
    assert((cashier.getBill({1, 2, 3, 4, 5, 6, 7}, {1, 1, 1, 1, 1, 1, 1}) - 800.00) < 0.00001);
    // 返回 4000.0
    assert((cashier.getBill({4}, {10}) - 4000.0) < 0.00001);
    // 返回 4000.0
    assert((cashier.getBill({7, 3}, {10, 10}) - 4000.0) < 0.00001);
    // 返回 7350.0 ，账单原本为 14700.0 ，但由于系统计数再次达到三，该顾客将得到 50% 的折扣，实际金额为 7350.0 。
    assert((cashier.getBill({7, 5, 3, 1, 6, 4, 2}, {10, 10, 10, 9, 9, 9, 7}) - 7350.0) < 0.00001);
    // 返回 2500.0
    assert((cashier.getBill({2, 3, 5}, {5, 3, 2}) - 2500.0) < 0.00001);
}
