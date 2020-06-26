#include "../include/header/list.hpp"
#include <unordered_set>

using namespace std;

class Solution
{
public:
    ListNode *removeDuplicateNodes(ListNode *head)
    {
        unordered_set<int> has;

        ListNode *cur = head;
        ListNode *pre = nullptr;

        while (cur)
        {
            if (has.find(cur->val) == has.end())
            {
                has.insert(cur->val);
                pre = cur;
            }
            else
            {
                pre->next = cur->next;
            }

            cur = cur->next;
        }

        return head;
    }
};

int main()
{
    Solution s;

    vector<int> a1 = {1, 2, 3, 3, 2, 1};
    vector<int> a2 = {1, 2, 3};
    auto l1 = ListNode::deserialize(a1);
    auto l2 = ListNode::deserialize(a2);
    assert(ListNode::equal(s.removeDuplicateNodes(l1), l2));

    vector<int> a3 = {1, 1, 1, 1, 2};
    vector<int> a4 = {1, 2};
    auto l3 = ListNode::deserialize(a3);
    auto l4 = ListNode::deserialize(a4);
    assert(ListNode::equal(s.removeDuplicateNodes(l3), l4));
}