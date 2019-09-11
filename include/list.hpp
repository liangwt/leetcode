#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}

    static vector<int> serialize(ListNode *head);

    static ListNode *deserialize(const vector<int> &arr);

    bool operator==(const ListNode *node) {
        auto n1 = node;
        auto n2 = this;

        while (n1 && n2) {
            if (n1->val != n2->val) {
                return false;
            }

            n1 = n1->next;
            n2 = n2->next;
        }

        return !(n1 || n2);
    }
};

ListNode *ListNode::deserialize(const vector<int> &arr) {
    if (arr.empty()) {
        return nullptr;
    }
    auto *n = new ListNode(arr[0]);
    ListNode *head = n, *tail = n;

    for (int i = 1; i < arr.size(); ++i) {
        n = new ListNode(arr[i]);
        tail->next = n;
        tail = n;
    }

    return head;
}

vector<int> ListNode::serialize(ListNode *head) {
    vector<int> result;
    auto n = head;

    while (n) {
        result.push_back(n->val);
        n = n->next;
    }

    return result;
}
