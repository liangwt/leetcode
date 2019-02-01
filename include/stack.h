#include <stdbool.h>

typedef struct _stack_node
{
    void *val;
    struct _stack_node *next;
} stack_node;

typedef struct _stack
{
    int num;
    stack_node *top;
    stack_node *bottom;
} stack;

void stack_init(stack *s);
bool stack_push(stack *s, void *val);
stack_node *stack_pop(stack *s);
void stack_destory(stack *s);
