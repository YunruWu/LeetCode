/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
 O(n) time, O(1) space
 */

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return NULL;
        
        int count = 1;
        ListNode* pre = head;
        while (pre->next) {
        	count++;
        	pre = pre->next;
        }

        return create(head, count);
    }

    TreeNode* create(ListNode* head, int count) {
        if (count == 0) return NULL;
    	ListNode* temp = head;
    	for (int i = 0; i < count / 2; i++) {
    		temp = temp->next;
    	}

    	TreeNode* root = new TreeNode(temp->val);
    	root->left = create(head, count / 2);
    	root->right = create(temp->next, count - count / 2 - 1);

    	return root;
    }
};