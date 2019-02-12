/**
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
 *
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 * Example:
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 */
#include <stdlib.h>
#include <limits.h>

typedef struct
{
    int val;
    int minVal;
} MinStackNode;

typedef struct
{
    int min;
    int index;
    MinStackNode stack[0];
} MinStack;

/** initialize your data structure here. */
MinStack *minStackCreate(int maxSize)
{
    MinStack *r = malloc(sizeof(MinStack) + maxSize * sizeof(MinStackNode));
    r->index = -1;
    r->min = INT_MAX;
    return r;
}

void minStackPush(MinStack *obj, int x)
{
    obj->index++;
    MinStackNode *node = &(obj->stack[obj->index]);
    node->val = x;
    node->minVal = obj->min;

    if (obj->min > x)
        obj->min = x;
}

void minStackPop(MinStack *obj)
{
    if (obj->index < 0)
        return;

    MinStackNode *node = &(obj->stack[obj->index]);

    if (obj->min == node->val)
        obj->min = node->minVal;

    obj->index--;
    return;
}

int minStackTop(MinStack *obj)
{
    MinStackNode *node = &(obj->stack[obj->index]);

    return node->val;
}

int minStackGetMin(MinStack *obj)
{
    return obj->min;
}

void minStackFree(MinStack *obj)
{
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * struct MinStack* obj = minStackCreate(maxSize);
 * minStackPush(obj, x);
 * minStackPop(obj);
 * int param_3 = minStackTop(obj);
 * int param_4 = minStackGetMin(obj);
 * minStackFree(obj);
 */