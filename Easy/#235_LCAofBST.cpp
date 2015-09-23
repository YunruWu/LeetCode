/*
O(n)
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q) return NULL;

        if (p->val < root->val && q->val < root->val)
        	return lowestCommonAncestor(root->left, p, q);
        else if (p->val > root->val && q->val > root->val)
        	return lowestCommonAncestor(root->right, p, q);
        else 
        	return root;
    }
};


// iterative Solution
class Solution { 
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur = root;
        while (true) {
            if (p -> val < cur -> val && q -> val < cur -> val)
                cur = cur -> left;
            else if (p -> val > cur -> val && q -> val > cur -> val)
                cur = cur -> right;
            else return cur; 
        }
    }
};