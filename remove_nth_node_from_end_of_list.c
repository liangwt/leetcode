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
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int l = 0;
    struct ListNode* node = head;

    while(node){
        l++;
        node=node->next;
    }

    int i = 0;
    struct ListNode* pre_node = NULL;
    struct ListNode* obj_node;

    while(i < l - n){
        if(i == 0){
            pre_node = head;
        }else{
            pre_node = pre_node->next;
        }
        i++;
    }

    // will remove first element
    if(!pre_node){
        obj_node = head->next;
        free(head);
        return obj_node;
    }

    obj_node =  pre_node->next;
    pre_node->next = pre_node->next->next;
    
    free(obj_node);
    
    return head;
}