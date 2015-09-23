class Solution {
public:
    void deleteNode(ListNode* node) {
    	// copy value of the next node
        node->val = node->next->val;
        node->next = node->next->next;
    }
};


class Solution {
public:
    void deleteNode(ListNode* node) {
        auto next = node->next;
        *node = *next;
        delete next;
    }
};