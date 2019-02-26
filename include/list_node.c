
#include <stdlib.h>
#include "list_node.h"

struct ListNode *list_create_from_arr(int *s, int num)
{
    if (num == 0)
    {
        return NULL;
    }

    struct ListNode *head = list_create_node(s[0]), *cur = head;

    for (int i = 1; i < num; i++)
    {
        cur->next = list_create_node(s[i]);
        cur = cur->next;
    }

    return head;
}

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

struct ListNode *list_get_idx_node(struct ListNode *l, int idx)
{
    struct ListNode *t = l;
    int i = 0;
    while (t)
    {
        if (i == idx)
        {
            return t;
        }
        i++;
        t = t->next;
    }

    return t;
}

int list_len(struct ListNode *l)
{
    struct ListNode *t = l;
    int i = 0;
    while (t)
    {
        i++;
        t = t->next;
    }

    return i;
}

void list_free(struct ListNode *l)
{
    struct ListNode *t;

    while (l)
    {
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