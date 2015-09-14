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
        	// insert a node after pre every time
        	// pre never moves
        	ListNode* temp = pre->next;
        	pre->next = pCur->next;
        	pre->next->next = temp;

        	// delete the node after pCur
        	// pCur always points to the orginal head
        	pCur->next = pCur->next->next;
        	// can't delete temp
        }

        return pre->next;
    }
};



// recursive Solution
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;  
          
        ListNode p = head.next;  
        ListNode n = reverseLisbt(p);  
          
        head.next = null;  
        p.next = head;  
        return n;
    }
};