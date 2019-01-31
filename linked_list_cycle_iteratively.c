#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

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
bool hasCycle(struct ListNode *head)
{
    if (!head || !head->next)
    {
        return false;
    }

    struct ListNode *slow = head;
    struct ListNode *fast = head->next;

    while (fast && fast->next)
    {
        if (slow == fast)
        {
            return true;
        }

        slow = slow->next;
        fast = fast->next->next;
    }

    return false;
}