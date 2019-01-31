#include <stdlib.h>
#include <stdbool.h>
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
bool isPalindrome(struct ListNode *head)
{
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    if (!head || !slow->next)
    {
        return true;
    }

    // slow相当于挨个遍历
    // fast相当于偶数遍历
    // 所以只需要遍历一次就可以找到中点
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode *pre = NULL;
    struct ListNode *nex = NULL;

    if (fast)
    {
        slow = slow->next;
    }

    while (slow)
    {
        nex = slow->next;
        slow->next = pre;

        pre = slow;
        slow = nex;
    }

    while (pre)
    {
        if (pre->val != head->val)
        {
            return false;
        }

        pre = pre->next;
        head = head->next;
    }

    return true;
}