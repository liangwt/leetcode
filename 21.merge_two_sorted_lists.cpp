/*
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 *
 * Example:
 *
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 */
#include "include/header/list.hpp"
#include <vector>

using namespace std;

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *cur = nullptr, *head = nullptr;
        while (l1 || l2)
        {
            ListNode *select;

            if (l1 && l2)
            {
                if (l1->val <= l2->val)
                {
                    select = l1;
                    l1 = l1->next;
                }
                else
                {
                    select = l2;
                    l2 = l2->next;
                }
            }
            else
            {
                if (!l1 && l2)
                {
                    select = l2;
                    l2 = l2->next;
                }
                else
                {
                    select = l1;
                    l1 = l1->next;
                }
            }

            if (!head)
            {
                head = select;
            }

            if (!cur)
            {
                cur = select;
            }
            else
            {
                cur->next = select;
                cur = select;
            }
        }

        return head;
    }
};

int main()
{
    Solution s;

    vector<int> a1 = {1, 2, 4};
    vector<int> a2 = {1, 3, 4};

    auto l1 = ListNode::deserialize(a1);
    auto l2 = ListNode::deserialize(a2);

    assert(ListNode::serialize(s.mergeTwoLists(l1, l2)) == vector<int>({1, 1, 2, 3, 4, 4}));

    return 0;
}