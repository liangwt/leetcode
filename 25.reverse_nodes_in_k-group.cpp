#include "include/header/list.hpp"

using namespace std;

class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *cur = head,
                 *start = head,
                 *end = nullptr,
                 *last_end = nullptr,
                 *ans = nullptr;

        int i = 1;

        while (cur)
        {
            if (i == k)
            {
                end = cur;

                if (!ans)
                {
                    ans = end;
                }

                cur = reverse(start, end);

                if (last_end)
                {
                    last_end->next = end;
                }
                last_end = start;

                start = cur;
                i = 1;
            }
            else
            {
                cur = cur->next;
                i++;
            }
        }

        if (last_end)
        {
            last_end->next = start;
            return ans;
        }

        return head;
    }

    ListNode *reverse(ListNode *start, ListNode *end)
    {
        ListNode *pre = nullptr, *cur = start, *next = cur->next;

        while (pre != end)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        return cur;
    }
};

int main()
{
    Solution s;

    vector<int> arr1 = {1, 2, 3, 4, 5};
    auto h1 = ListNode::deserialize(arr1);

    assert(ListNode::serialize(s.reverseKGroup(h1, 2)) == vector<int>({2, 1, 4, 3, 5}));
}