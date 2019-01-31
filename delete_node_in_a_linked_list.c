#include <stdlib.h>

int main()
{
}

struct ListNode
{
    int val;
    struct ListNode *next;
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 * 
 * 这道题的处理方法是先把当前节点的值用下一个节点的值覆盖了，
 * 然后我们删除下一个节点
 * 
 */
void deleteNode(struct ListNode *node)
{
    struct ListNode *next = node->next;

    (*node).val = next->val;
    (*node).next = next->next;

    free(next);
}