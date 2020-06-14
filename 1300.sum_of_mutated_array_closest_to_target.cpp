#include <vector>
#include <math.h>

using namespace std;

class Solution
{
public:
    int findBestValue(vector<int> &arr, int target)
    {
        if (arr.empty())
        {
            return 0;
        }

        sort(arr.begin(), arr.end());

        int sum = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            double last = target - sum;

            int need = floor(last / (arr.size() - i) + 0.4);

            if (need > arr[i])
            {
                sum += arr[i];
            }
            else
            {
                return need;
            }
        }

        return arr[arr.size() - 1];
    }
};

int main()
{
    Solution s;

    vector<int> a1 = {4, 9, 3};
    assert(s.findBestValue(a1, 10) == 3);

    vector<int> a2 = {2, 3, 5};
    assert(s.findBestValue(a2, 10) == 5);

    vector<int> a3 = {60864, 25176, 27249, 21296, 20204};
    assert(s.findBestValue(a3, 56803) == 11361);
}