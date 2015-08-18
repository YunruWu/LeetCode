/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
O(n)
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    	// empty list
        if (head == NULL)
			return NULL;
		
		ListNode* pcount = head;
		ListNode* prev = head;
		ListNode* last = head->next;

		// count the list
		int i = 1;
		while(pcount->next != NULL){
			i++;
			pcount = pcount->next;
		}

		// if demand to remove the first node
		if (i == n)
			return head->next;

		for (int j = 0; j < i & last != NULL; j++){
			if (j == i-n-1){			
				// traverse from the head to delete the i-n node
				prev->next = last->next;
				break;
			}
			prev = last;
			last = last->next;
		}
		
		return head;
    }
};