/**
 *Write a program to find the node at which the intersection of two singly linked lists begins.
 * 
 * For example, the following two linked lists:
 * 
 * https://assets.leetcode.com/uploads/2018/12/13/160_statement.png
 * 
 * begin to intersect at node c1.
 * 
 *  
 * 
 * Example 1:
 * 
 * https://assets.leetcode.com/uploads/2018/12/13/160_example_1.png
 * 
 * Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
 * Output: Reference of the node with value = 8
 * Input Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect). From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,0,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
 *  
 * 
 * Example 2:
 * 
 * https://assets.leetcode.com/uploads/2018/12/13/160_example_2.png
 * 
 * Input: intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
 * Output: Reference of the node with value = 2
 * Input Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect). From the head of A, it reads as [0,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.
 *  
 * 
 * Example 3:
 * 
 * https://assets.leetcode.com/uploads/2018/12/13/160_example_3.png
 * 
 * Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
 * Output: null
 * Input Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.
 * Explanation: The two lists do not intersect, so return null.
 *  
 * 
 * Notes:
 * 
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function returns.
 * You may assume there are no cycles anywhere in the entire linked structure.
 * Your code should preferably run in O(n) time and use only O(1) memory.
 */

#include <stdlib.h>
#include <stdio.h>
#include "include/list_node.h"

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB);

int main()
{
    int p1[3] = {1, 2, 3};
    struct ListNode *headA = list_create_from_arr(p1, 3);
    struct ListNode *headB = list_create_from_arr(p1, 3);

    int p2[4] = {5, 6, 7, 9};
    struct ListNode *list = list_create_from_arr(p2, 4);

    struct ListNode *nodeA = list_get_idx_node(headA, 2);
    struct ListNode *nodeB = list_get_idx_node(headB, 2);

    nodeA->next = list;
    nodeB->next = list;

    struct ListNode *r = getIntersectionNode(headA, headB), *t = r;
    while (t)
    {
        printf("%d->", t->val);
        t = t->next;
    }
}

/**
 * 如果链表有相交的话，那么相交点后面的元素都是一样的
 * 而相交点前面的元素个数差值就是两个链表总长度的差值
 * 
 * 所以把较长的链表向后移动这个差值，然后两个链表对应的节点一一对比
 * 就能找到相交的节点了
 * 
 * 1. 求出两个链表的长度
 * 2. 从较长的链表减去差值的位置与较短链表的头部开始一一对比
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
    int len_a = list_len(headA), len_b = list_len(headB);
    struct ListNode *cur_short, *cur_long;

    if (len_a > len_b)
    {
        cur_short = headB;
        cur_long = list_get_idx_node(headA, len_a - len_b);
    }
    else if (len_a == len_b)
    {
        cur_short = headA;
        cur_long = headB;
    }
    else
    {
        cur_short = headA;
        cur_long = list_get_idx_node(headB, len_b - len_a);
    }

    while (cur_long && cur_short)
    {
        if (cur_long == cur_short)
        {
            return cur_long;
        }
        cur_long = cur_long->next;
        cur_short = cur_short->next;
    }

    return NULL;
}