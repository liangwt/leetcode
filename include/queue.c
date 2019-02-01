#include <stdlib.h>
#include <stdbool.h>
#include "queue.h"

void queue_init(queue *q)
{
    q->num = 0;
    q->head = NULL;
    q->tail = NULL;

    return;
}

bool queue_is_empty(queue *q){
    return q->num == 0;
}

int queue_length(queue *q)
{
    return q->num;
}

bool queue_push(queue *q, void *val)
{
    queue_node *node = malloc(sizeof(queue_node));
    if (!node)
    {
        return false;
    }

    node->val = val;
    node->next = q->head;
    node->pre = NULL;

    if (q->head)
    {
        q->head->pre = node;
    }
    else
    {
        q->tail = node;
    }

    q->head = node;

    q->num++;

    return true;
}

queue_node *queue_pop(queue *q)
{
    if (!q->tail)
    {
        return NULL;
    }

    queue_node *node = q->tail;

    q->tail = q->tail->pre;

    if (!q->tail)
    {
        q->head = NULL;
    }

    q->num--;

    return node;
}

void queue_destory(queue *q)
{
    queue_node *node = q->head;
    queue_node *tmp = NULL;
    while (node)
    {
        tmp = node;
        node = node->next;
        free(tmp);
    }

    q->num = 0;
    q->head = NULL;
    q->tail = NULL;
}
