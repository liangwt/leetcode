#include <stdlib.h>
#include <stdbool.h>

int main()
{
}

typedef struct _stack_node
{
    void *val;
    struct _stack_node *next
} stack_node;

typedef struct _stack
{
    stack_node *top;
    stack_node *bottom;
} stack;

void stact_init(stack *s)
{
    s->top = malloc(sizeof(stack_node));
    if (s->top == NULL)
    {
        exit(-1);
    }
    s->bottom = s->top;
    s->top->next = NULL;
    return;
}

bool stack_push(stack *s, void *val)
{
    stack_node * node = malloc(sizeof(stack_node));
    if(node==NULL){
        return false;
    }
    node->val = val;
    node->next = s->top;
    s->top = node;

    return true;
}

bool stack_pop(stack *s){

}

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return 1 + MAX(maxDepth(root->left), maxDepth(root->right));
}
