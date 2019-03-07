#include <stdlib.h>
#include "queue.h"
#include "tree_node.h"

struct TreeNode *tree_create_node(int val) {
    struct TreeNode *node = malloc(sizeof(struct TreeNode) * 1);
    node->val = val;
    node->left = NULL;
    node->right = NULL;

    return node;
}

struct TreeNode *tree_create_from_arr(int *s, int num) {
    if (num == 0) {
        return NULL;
    }

    queue q;
    queue *qp = &q;
    queue_init(&q);

    struct TreeNode *root = tree_create_node(s[0]);
    queue_push(qp, root);

    struct TreeNode *node;
    struct TreeNode *l_node;
    struct TreeNode *r_node;

    int i = 1;
    while (i < num) {
        node = queue_pop(qp)->val;

        if (s[i] != NULL_NODE) {
            l_node = tree_create_node(s[i]);
            queue_push(qp, l_node);
            node->left = l_node;
        }

        i++;

        if (i >= num) {
            break;
        }

        if (s[i] != NULL_NODE) {
            r_node = tree_create_node(s[i]);
            queue_push(qp, r_node);
            node->right = r_node;
        }

        i++;
    }

    return root;
}
