/**
 * Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.
 * 
 * You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
 * 
 * Example 1:
 * 
 * Input: 1->2->3->4->5->NULL
 * Output: 1->3->5->2->4->NULL
 * Example 2:
 * 
 * Input: 2->1->3->5->6->4->7->NULL
 * Output: 2->3->6->7->1->5->4->NULL
 * Note:
 * 
 * The relative order inside both the even and odd groups should remain as it was in the input.
 * The first node is considered odd, the second node even and so on ...
 */
#include <stdlib.h>
#include <stdio.h>
#include "include/list_node.h"

struct ListNode *oddEvenList(struct ListNode *head);

int main()
{
    struct ListNode *head = list_create_node(1);
    struct ListNode *l = head;

    for (int i = 2; i <= 6; i++)
    {
        l = list_append_val(l, i);
    }

    l = oddEvenList(head);

    while (l)
    {
        printf(" %d -> ", l->val);
        l = l->next;
    }

    list_free(head);
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *oddEvenList(struct ListNode *head)
{
    if (!head)
        return NULL;

    struct ListNode *odd_head = head;
    struct ListNode *even_head = head->next;

    struct ListNode *list_cur = head;
    struct ListNode *even_cur = head->next;

    while (even_cur && even_cur->next)
    {
        list_cur->next = even_cur->next;
        list_cur = list_cur->next;
        if (list_cur)
        {
            even_cur->next = list_cur->next;
            even_cur = even_cur->next;
        }
    }
    if (even_cur)
        even_cur->next = NULL;

    list_cur->next = even_head;

    return odd_head;
}