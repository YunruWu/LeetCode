/*
O(n)
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* super_head = new ListNode(0);
        super_head->next = head;
        ListNode* pre = super_head;
        ListNode* pCur = head;

        while (pCur && pCur->next)
        {
        	ListNode* temp = pre->next;
        	pre->next = pCur->next;
        	pre->next->next = temp;

        	pCur->next = pCur->next->next;
        	delete temp;
        }

        return super_head->next;
    }
};


// recursive solution
class Solution {
public:   
    ListNode* reverseList(ListNode* head) {
        if (!head || !(head -> next)) return head;
        ListNode* node = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = NULL;
        return node; 
    }
}; 