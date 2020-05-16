#include "include/header/list.hpp"

using namespace std;

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head)
        {
            return nullptr;
        }

        ListNode *cur = head->next, *pre = head, *ans = head;

        while (cur)
        {
            if (cur->val != pre->val)
            {
                pre->next = cur;
                pre = cur;
            }

            cur = cur->next;
        }

        pre->next = nullptr;
        return ans;
    }
};

int main()
{
    Solution s;
    vector<int> arr1 = {1, 1, 2, 3, 3};
    auto h1 = ListNode::deserialize(arr1);
    assert(ListNode::serialize(s.deleteDuplicates(h1)) == vector<int>({1, 2, 3}));
}