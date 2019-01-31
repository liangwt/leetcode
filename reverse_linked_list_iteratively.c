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
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* pre_node = NULL;
    struct ListNode* cur_node = head;
    struct ListNode* nex_node;

    while(cur_node){
        nex_node = cur_node->next;
        cur_node->next = pre_node;
        pre_node = cur_node;
        cur_node = nex_node;
    }

    return pre_node;
}