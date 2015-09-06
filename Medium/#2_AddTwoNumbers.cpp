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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // similar to #67 Add Binary
        ListNode* l3 = new ListNode(0);
        ListNode* p3 = l3;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        int extra = 0;

        while (p1 || p2 || extra)	// extra作为或的条件之一包含了最高位还要进1的情况
        {
        	int num1 = 0, num2 = 0;
        	if (p1)
        	{
        		num1 = p1->val;
        		p1 = p1->next;
        	}
        	if (p2)
        	{
        		num2 = p2->val;
        		p2 = p2->next;
        	}

        	p3->next = new ListNode((num1 + num2 + extra) % 10);
        	p3 = p3->next;
        	extra = (num1 + num2 + extra) / 10;

        }

        return l3->next;
    }
};