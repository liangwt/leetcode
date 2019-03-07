#include <limits.h>

#define NULL_NODE INT_MAX

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *tree_create_node(int val);

struct TreeNode *tree_create_from_arr(int *s, int num);