#include <stdlib.h>
#include <stdbool.h>

typedef struct _queue_node
{
    void *val;
    struct _queue_node *next;
    struct _queue_node *pre;
} queue_node;

typedef struct _queue
{
    int num;
    struct _queue_node *head;
    struct _queue_node *tail;
} queue;

void queue_init(queue *q);
bool queue_is_empty(queue *q);
int queue_length(queue *q);
bool queue_push(queue *q, void *val);
queue_node *queue_pop(queue *q);
void queue_destory(queue *q);
