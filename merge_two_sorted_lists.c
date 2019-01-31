#include <stdlib.h>
#include <limits.h>

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
 */
struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *cur = NULL;
    struct ListNode *head = NULL;
    struct ListNode *node = NULL;
    struct ListNode *node1 = l1;
    struct ListNode *node2 = l2;
    while (node1 || node2)
    {
        int val1 = node1 ? node1->val : INT_MAX;
        int val2 = node2 ? node2->val : INT_MAX;
        if (val1 > val2)
        {
            node = node2;
            node2 = node2->next;
        }
        else
        {
            node = node1;
            node1 = node1->next;
        }

        if (!head)
        {
            head = node;
            cur = node;
        }
        else
        {
            cur->next = node;
            cur = node;
        }
    }

    return head;
}