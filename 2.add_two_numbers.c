/**
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * 
 * Example:
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 */
#include <stdio.h>
#include "include/list_node.h"

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2);

int main()
{
    struct ListNode *l1 = list_create_node(2);
    l1->next = list_create_node(4);
    l1->next->next = list_create_node(3);

    struct ListNode *l2 = list_create_node(5);
    l2->next = list_create_node(6);
    l2->next->next = list_create_node(4);

    struct ListNode *l3 = addTwoNumbers(l1, l2);
    struct ListNode *l4 = l3;
    while (l4)
    {
        printf("an: %d\n", l4->val);
        l4 = l4->next;
    }

    list_free(l1);
    list_free(l2);
    list_free(l3);
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    struct ListNode *node1 = l1;
    struct ListNode *node2 = l2;
    struct ListNode *node3 = list_create_node(0);
    struct ListNode *node4 = node3;
    int v = 0, f = 0;

    while (node1 || node2)
    {
        int v1 = 0, v2 = 0;
        if (node1)
        {
            v1 = node1->val;
            node1 = node1->next;
        }

        if (node2)
        {
            v2 = node2->val;
            node2 = node2->next;
        }

        v = (v1 + v2 + f) % 10;
        f = (v1 + v2 + f) / 10;

        node3 = list_append_val(node3, v);
    }

    if (f != 0)
    {
        node3 = list_append_val(node3, f);
    }

    struct ListNode *node5 = node4->next;
    list_free_node(node4);

    return node5;
}