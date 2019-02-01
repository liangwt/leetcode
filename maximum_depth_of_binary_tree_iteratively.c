#include <stdlib.h>
#include <stdbool.h>
#include "include/queue.h"

int main()
{
}

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int maxDepth(struct TreeNode *root)
{
    if (!root)
    {
        return 0;
    }

    int i = 0, j = 0;
    queue q;
    queue_node *q_node;
    struct TreeNode *t_node;

    queue_init(&q);
    queue_push(&q, root);
    while (!queue_is_empty(&q))
    {
        i++;
        for (j = queue_length(&q); j > 0; j--)
        {
            q_node = queue_pop(&q);
            t_node = (struct TreeNode *)q_node->val;
            if (t_node->left)
                queue_push(&q, t_node->left);
            if (t_node->right)
                queue_push(&q, t_node->right);
        }
    }

    return i;
}
