/*
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

 */

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return createTree(1, n);
    }

    vector<TreeNode*> createTree(int start, int end) {
    	vector<TreeNode*> result;
    	if (start > end) {
    		result.push_back(NULL);
    		return result;
    	}

    	for (int i = start; i < end; i++) {
    		vector<TreeNode*> left = createTree(start, i-1);
    		vector<TreeNode*> right = createTree(i+1, end);
    		for (int j = 0; j < left.size(); j++) {
    			for (int k = 0; k < right.size(); k++) {
    				TreeNode* root = new TreeNode(i);
    				root->left = left[j];
    				root->right = right[k];
    				result.push_back(root);
    			}
    		}
    	}

    	return result;
    }
};