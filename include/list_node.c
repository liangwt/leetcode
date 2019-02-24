
#include <stdlib.h>
#include "list_node.h"

struct ListNode *list_create_node(int val)
{
    struct ListNode *l = malloc(sizeof(struct ListNode) * 1);
    l->val = val;
    l->next = NULL;

    return l;
}

struct ListNode *list_insert_node(struct ListNode *l, struct ListNode *node)
{
    node->next = l->next;
    l->next = node;

    return node;
}

struct ListNode *list_insert_val(struct ListNode *l, int val)
{
    struct ListNode *node = list_create_node(val);
    node->next = l->next;
    l->next = node;

    return node;
}

struct ListNode *list_append_node(struct ListNode *l, struct ListNode *node)
{
    l->next = node;

    return node;
}

struct ListNode *list_append_val(struct ListNode *l, int val)
{
    struct ListNode *node = list_create_node(val);
    l->next = node;

    return node;
}

void list_free(struct ListNode *l)
{
    struct ListNode *t;

    while(l){
        t = l;
        l = l->next;
        free(t);
    }
    
    return;
}

void list_free_node(struct ListNode *l)
{
    free(l);
    return;
}