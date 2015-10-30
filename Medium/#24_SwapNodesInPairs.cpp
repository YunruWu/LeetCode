/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

 */

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* pre = new ListNode(0);
        pre->next = head;
        ListNode* superhead = pre;

        ListNode* fast = pre;
        ListNode* slow = pre;

        while (fast->next && fast->next->next) {
        	slow = fast->next;
        	fast = fast->next->next;
        	ListNode* temp = fast->next;
        	fast->next = slow;
        	pre->next = fast;
        	slow->next = temp;
        	pre = slow;
        	fast = slow;
        }

        return superhead->next;
    }
};