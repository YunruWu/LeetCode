/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
 */

// If a duplicate is detected, firstly move to the next different number, 
// and link it to its prefix.
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* superhead = new ListNode(0);
        superhead->next = head;
        ListNode* pre = superhead;

        int flag = 0;
        ListNode* temp = head;
        while (temp) {
        	ListNode* cur = temp->next;
        	if (cur && cur->val == temp->val) {
        		while (cur && cur->val == temp->val) {
        			cur = cur->next;
        		}
        		temp = cur;
        		pre->next = temp;
        	}
        	else {
        		pre = temp;
        		temp = temp->next;
        	}
        }
        
        
        return superhead->next;
    }
};