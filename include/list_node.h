struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *list_create_node(int val);
struct ListNode *list_insert_node(struct ListNode *l, struct ListNode *node);
struct ListNode *list_insert_val(struct ListNode *l, int val);
struct ListNode *list_append_node(struct ListNode *l, struct ListNode *node);
struct ListNode *list_append_val(struct ListNode *l, int val);
void list_free(struct ListNode *l);
void list_free_node(struct ListNode *l);