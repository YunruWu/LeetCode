/*
O(n)
 */

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode* slow = head;
        ListNode* fast = head;

        /* TLE
        while (fast->next && fast->next->next)
        {
        	fast = reverseList(fast->next);
        	if (slow->val != fast->val) return false;
        	slow = fast->next;
        	fast = slow;
        } */

        while(fast->next!=NULL&&fast->next->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverseList(slow->next);
        slow=slow->next;
        while(slow!=NULL)
        {
            if(head->val!=slow->val)
                return false;
            head=head->next;
            slow=slow->next;
        }

        return true;
    }

    ListNode* reverseList(ListNode* head) {
    	ListNode* pre = NULL;
    	ListNode* next = NULL;
    	while (head)
    	{
    		next = head->next;
    		head->next = pre;
    		pre = head;
    		head = next;
    	}
    	return pre;
    }
};