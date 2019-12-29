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

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (!l1 && !l2) {
            return nullptr;
        }

        ListNode *head, *tail;

        if (l1 && l2) {
            if (l1->val < l2->val) {
                head = l1;
                tail = l1;
                l1 = l1->next;
            } else {
                head = l2;
                tail = l2;
                l2 = l2->next;
            }
        } else if (l1) {
            head = l1;
            tail = l1;
            l1 = l1->next;
        } else {
            head = l2;
            tail = l2;
            l2 = l2->next;
        }

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                tail = l1;
                l1 = l1->next;

            } else {
                tail->next = l2;
                tail = l2;
                l2 = l2->next;
            }
        }

        if(l1){
            tail->next = l1;
        }

        if(l2){
            tail->next = l2;
        }

        return head;
    }
};

int main() {
    Solution s;

    vector<int> a1 = {1, 2, 4};
    vector<int> a2 = {1, 3, 4};

    auto l1 = ListNode::deserialize(a1);
    auto l2 = ListNode::deserialize(a2);

    assert(ListNode::serialize(s.mergeTwoLists(l1, l2)) == vector<int>({1, 1, 2, 3, 4, 4}));


    return 0;
}