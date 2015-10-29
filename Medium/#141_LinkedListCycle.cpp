/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next) return false;
        ListNode* faster = head;
        ListNode* slower = head;

        while (faster->next && faster->next->next) {
        	slower = slower->next;
        	faster = faster->next->next;
        	if (faster == slower) {
        		return true;
        	}
        }

        return false;
    }
};