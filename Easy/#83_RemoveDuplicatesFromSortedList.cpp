/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *
 * O(n)
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // handle empty list
        if (head == NULL)
        	return NULL;

        ListNode* current = head->next;
        ListNode* p = head;

        while (current)
        {
        	if (current->val == p->val)	
        		p->next = current->next;	// delete duplicate nodes
        	else 
        	    p = current;	// move p to the new node
        	current = current->next;	
        }

        return head;
    }
};