#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

void stack_init(stack *s) {
    s->bottom = NULL;
    s->top = NULL;
    s->num = 0;
    return;
}

bool stack_is_empty(stack *s) {
    return s->num == 0;
}

void *stack_top(stack *s) {
    return s->top->val;
}

bool stack_push(stack *s, void *val) {
    stack_node *node = malloc(sizeof(stack_node));
    if (node == NULL) {
        return false;
    }
    node->val = val;
    node->next = s->top;
    s->top = node;
    s->num++;

    if (!s->bottom) {
        s->bottom = node;
    }

    return true;
}

void *stack_pop(stack *s) {
    if (!s->top) {
        return NULL;
    }
    stack_node *node = s->top;
    s->top = s->top->next;
    s->num--;
    if (!s->top) {
        s->bottom = NULL;
    }

    return node->val;
}

void stack_destory(stack *s) {
    stack_node *node = s->top;
    stack_node *tmp = node;
    while (node) {
        tmp = node;
        node = node->next;
        free(tmp);
    }
    s->top = NULL;
    s->bottom = NULL;
    s->num = 0;
    return;
}