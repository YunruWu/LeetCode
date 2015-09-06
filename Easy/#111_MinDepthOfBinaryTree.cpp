/*
O(n)
 */

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        if (!root->right) return minDepth(root->left) + 1;
        if (!root->left) return minDepth(root->right) + 1;
        else
        	return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};