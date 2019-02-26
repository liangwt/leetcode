struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode *list_create_from_arr(int *s, int num);
struct ListNode *list_create_node(int val);
struct ListNode *list_insert_node(struct ListNode *l, struct ListNode *node);
struct ListNode *list_insert_val(struct ListNode *l, int val);
struct ListNode *list_append_node(struct ListNode *l, struct ListNode *node);
struct ListNode *list_append_val(struct ListNode *l, int val);
struct ListNode *list_get_idx_node(struct ListNode *l, int idx);
int list_len(struct ListNode *l);
void list_free(struct ListNode *l);
void list_free_node(struct ListNode *l);