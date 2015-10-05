/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 * O(n)
 */
/*
 * iterative method
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;

        stack<TreeNode*> st;
        st.push(root->left);
        st.push(root->right);

        TreeNode *pl, *pr;
        while (!st.empty())
        {
        	pl = st.top();
        	st.pop();
        	pr = st.top();
        	st.pop();

        	if (!pl && !pr) continue;	// current nodes are null, still can be symmetric
        	if (!pl || !pr) return false;	// one is null, can't be symmetric
        	if (pl->val != pr->val) return false;	// unequal values

        	// take care of the sequence
        	st.push(pl->left);
        	st.push(pr->right);
        	st.push(pl->right);
        	st.push(pr->left);
        }

        return true;
    }
};


/*
 * recursive method	
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
    	if (!root) return true;
    	return isSymmetric_helper(root->left, root->right);
	}

	bool isSymmetric_helper(TreeNode* root1, TreeNode* root2) {
    	if (root1 == NULL && root2 == NULL) return true;
    	if (root1 == NULL || root2 == NULL) return false;
    	if (root1->val != root2->val) return false;
    	return isSymmetric_helper(root1->left, root2->right) && isSymmetric_helper(root1->right, root2->left);
	}
};