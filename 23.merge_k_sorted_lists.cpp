/*
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 *
 * Example:
 *
 * Input:
 * [
 *   1->4->5,
 *   1->3->4,
 *   2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
 */

/*
 * 思路一：
 *
 * 对于k个链表，可以通过不断的两两合并，直到合并成一个链表
 *
 * 思路二：
 *
 * 使用最小堆，先把k个链表堆头节点加入到堆中，
 * 逐个从堆中弹出最小节点，接到返回的链表的最后，并把弹出的节点的下一个节点入堆
 *
 * 当堆全部被弹出之后，返回拼接好的链表即可
 */

#include <vector>
#include <queue>

#include "include/list.hpp"

using namespace std;

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        auto cmp = [](ListNode *x, ListNode *y) -> bool { return x->val > y->val; };

        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> pri(cmp);
        ListNode *node;
        ListNode *head = new ListNode(-1), *tail = head;

        for (auto list : lists) {
            if (list) {
                pri.push(list);
            }
        }

        while (!pri.empty()) {
            node = pri.top();
            tail->next = node;
            tail = node;
            pri.pop();

            if (node->next) {
                pri.push(node->next);
            }
        }

        ListNode *result = head->next;

        delete head;
        return result;
    }
};

int main() {
    Solution s;

    vector<ListNode *> l1 = {
        ListNode::deserialize({1, 4, 5}),
        ListNode::deserialize({1, 3, 4}),
        ListNode::deserialize({2, 6}),
    };

    assert(ListNode::serialize(s.mergeKLists(l1)) == vector<int>({1, 1, 2, 3, 4, 4, 5, 6}));

    vector<ListNode *> l2 = {
        {}
    };

    assert(!s.mergeKLists(l2));

    return 0;
}