#include <stack>
#include "include/header/list.hpp"

#include <iostream>

using namespace std;

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        stack<int> st1;
        stack<int> st2;

        while (l1)
        {
            st1.push(l1->val);
            l1 = l1->next;
        }

        while (l2)
        {
            st2.push(l2->val);
            l2 = l2->next;
        }

        char overflow = 0;
        ListNode *node = nullptr;

        while (!st1.empty() || !st2.empty() || overflow)
        {
            int l = 0, r = 0;

            if (!st1.empty())
            {
                l = st1.top();
                st1.pop();
            }

            if (!st2.empty())
            {
                r = st2.top();
                st2.pop();
            }

            int total = l + r + overflow;

            if (total >= 10)
            {
                total -= 10;
                overflow = 1;
            }
            else
            {
                overflow = 0;
            }

            ListNode *n = new ListNode(total);

            if (node == nullptr)
            {
                node = n;
            }
            else
            {
                n->next = node;
                node = n;
            }
        }
        return node;
    }
};

int main()
{
    Solution s;
    auto l1 = ListNode::deserialize(vector<int>{7, 2, 4, 3});
    auto l2 = ListNode::deserialize(vector<int>{5, 6, 4});
    auto ans = ListNode::deserialize(vector<int>{7, 8, 0, 7});

    assert(ListNode::equal(s.addTwoNumbers(l1, l2), ans));

    l1 = ListNode::deserialize(vector<int>{5});
    l2 = ListNode::deserialize(vector<int>{5});
    ans = ListNode::deserialize(vector<int>{1, 0});

    assert(ListNode::equal(s.addTwoNumbers(l1, l2), ans));
}
