/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
 */

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        ListNode* pre = head;
        int n = 1;
        while (pre->next) {
        	n++;
        	pre = pre->next;
        }
        ListNode* end = pre;
        pre = head;

        if (k % n == 0) return head;
        int step = n - k % n;
        for (int i = 1; i < step; i++) {
        	pre = pre->next;
        }
        ListNode* newhead = pre->next;
        end->next = head;
        pre->next = NULL;

        return newhead;
    }
};