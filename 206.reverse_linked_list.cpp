/*
 * Reverse a singly linked list.
 *
 * Example:
 *
 * Input: 1->2->3->4->5->NULL
 * Output: 5->4->3->2->1->NULL
 * Follow up:
 *
 * A linked list can be reversed either iteratively or recursively. Could you implement both?
 */

/*
 * 三个指针，一个指向当前元素cur，一个指向下一个元素nxt，
 * 因为会把nxt指向到cur，所以需要一个指针记录断开的链表头节点bak
 *
 * 当nxt指向了cur则实现了一个反转，此时cur、nxt、bak全部往后移动一位
 */

#include "include/header/list.hpp"

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *cur = nullptr;
        ListNode *nxt = head;
        ListNode *bak;

        while (nxt) {
            bak = nxt->next;
            nxt->next = cur;
            cur = nxt;
            nxt = bak;
        }

        return cur;
    }
};


int main() {
    Solution s;

    vector<int> a1 = {1, 2, 3, 4, 5};
    auto l1 = ListNode::deserialize(a1);
    assert(ListNode::serialize(s.reverseList(l1)) == vector<int>({5, 4, 3, 2, 1}));

    vector<int> a2 = {};
    auto l2 = ListNode::deserialize(a2);
    assert(ListNode::serialize(s.reverseList(l2)) == vector<int>({}));

    return 0;
}