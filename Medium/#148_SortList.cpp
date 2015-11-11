/*
Sort a linked list in O(n log n) time using constant space complexity.
 */

class Solution {
public:
    ListNode* mergeList(ListNode* head, ListNode* mid) {
    	ListNode* newhead = new ListNode(0);
    	ListNode* temp = newhead;
    	while (head || mid) {
    		if (head && (!mid || head->val <= mid->val)) {
    			temp->next = head;
    			temp = temp->next;
    			head = head->next;
    		}
    		if (mid && (!head || mid->val < head->val)) {
    			temp->next = mid;
    			temp = temp->next;
    			mid = mid->next;
    		}
    	}

    	temp->next = NULL;
    	return newhead->next;
    }

    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast && fast->next) { // fast can be the last to NULL
        	fast = fast->next->next;
        	slow = slow->next;
        }
        ListNode* mid = slow->next;
        slow->next = NULL;
        return mergeList(sortList(head),sortList(mid));
    }

};