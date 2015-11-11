/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
 */

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head) return NULL;
       	ListNode* superhead = new ListNode(0);
       	superhead->next = head;
        ListNode* pre = superhead;

        // find the beginning and its pre and next
        for (int i = 0; i < m - 1; i++) {
        	pre = pre->next;
        }
        ListNode* begin = pre->next;
        ListNode* cur = begin->next;

        for (int i = 0; i < n-m; i++) {
        	begin->next = cur->next;
        	cur->next = pre->next;
        	pre->next = cur;
        	cur = begin->next; 
        }

        return superhead->next;
    }
};