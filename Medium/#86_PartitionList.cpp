/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
 */

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* superhead = new ListNode(0);
        superhead->next = head;
        ListNode* last_smaller = superhead;

        // find the first node larger than x
        while (last_smaller->next && last_smaller->next->val < x) {
        	last_smaller = last_smaller->next;
        }
        ListNode* larger = last_smaller;

        ListNode* temp;
        while (larger->next) {
        	temp = larger->next;
        	if (temp->val < x) {
        		larger->next = temp->next;
        		temp->next = last_smaller->next;
        		last_smaller->next = temp;
        		last_smaller = last_smaller->next;
        	}
        	else {
        		larger = larger->next;
        	}
        }

        return superhead->next;
    }
};