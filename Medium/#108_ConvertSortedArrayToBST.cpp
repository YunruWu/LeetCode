/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
 
An empty tree is height-balanced. A non-empty binary tree T is balanced if:
1) Left subtree of T is balanced
2) Right subtree of T is balanced
3) The difference between heights of left subtree and right subtree is not more than 1.
 */

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return NULL;
        return convert(nums, 0, nums.size()-1);
    }

    TreeNode* convert(vector<int>& nums, int start, int end) {
    	if (start > end) return NULL;
    	int middle = (start + end) / 2;
    	TreeNode* root = new TreeNode(nums[middle]);
    	root->left = convert(nums, start, middle - 1);
    	root->right = convert(nums, middle + 1, end);
    	return root;
    }
};