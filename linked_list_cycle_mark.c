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
    struct ListNode *cur = head;
    while (cur)
    {
        if (cur->val == INT_MAX)
        {
            return true;
        }
        cur->val = INT_MAX;
        cur = cur->next;
    }
    return false;
}