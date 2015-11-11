/*
Sort a linked list using insertion sort.
 */

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* superhead = new ListNode(0);
        superhead->next = head;
        ListNode* pre = superhead;
        ListNode* cur = head;

        while (cur && cur->next) {
        	if (cur->val > cur->next->val) {
        		while (pre->next) {
        			if (pre->next->val <= cur->next->val) {
        				pre = pre->next;
        			}
        			else
        				break;
        		}
        		ListNode* node = new ListNode(cur->next->val);
        		node->next = pre->next;
        		pre->next = node;
        		pre = superhead;
        		cur->next = cur->next->next;
        		/* Insert cur -> next after pre.
                ListNode* temp = pre -> next;
                pre -> next = cur -> next;
                cur -> next = cur -> next -> next;
                pre -> next -> next = temp;
                */
        	}
        	else {
        		cur = cur->next;
        		//pre = pre->next;
        	}
        }

        return superhead->next;
    }
};


// clean code
public ListNode insertionSortList(ListNode head) {
        if( head == null ){
            return head;
        }

        ListNode helper = new ListNode(0); //new starter of the sorted list
        ListNode cur = head; //the node will be inserted
        ListNode pre = helper; //insert node between pre and pre.next
        ListNode next = null; //the next node will be inserted
        //not the end of input list
        while( cur != null ){
            next = cur.next;
            //find the right place to insert
            while( pre.next != null && pre.next.val < cur.val ){
                pre = pre.next;
            }
            //insert between pre and pre.next
            cur.next = pre.next;
            pre.next = cur;
            pre = helper;
            cur = next;
        }

        return helper.next;
    }