/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return ;
        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast && fast->next) { // fast can be the last to NULL
        	fast = fast->next->next;
        	slow = slow->next;
        }
        ListNode* mid = slow->next;
        slow->next = NULL;
        ListNode* head2 = NULL;

        // reverse the second half
        while (mid) {
        	ListNode* cur = mid->next;
        	mid->next = head2;
        	head2 = mid;
        	mid = cur;
        }

        // merge the two lists
        while (head2) {
        	ListNode* temp1 = head->next;
        	ListNode* temp2 = head2->next;
        	head->next = head2;
        	head2->next = temp1;
        	head2 = temp2;
        	head = temp1;
        }

        return;
    }
};