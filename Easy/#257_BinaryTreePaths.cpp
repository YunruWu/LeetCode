/*
O(n)
 */

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
  		if (!root) return result;

  		findPaths(result, root, to_string(root->val));
  		return result;
    }

    void findPaths(vector<string>& result, TreeNode* root, string path) {
    	if (!root->left && !root->right)
    		result.push_back(path);

    	if (root->left)
    	{
    		//path += "->" + to_string(root->left->val);
    		findPaths(result, root->left, path + "->" + to_string(root->left->val));
    	}
        
        if (root->right)
    	{
    		//path += "->" + to_string(root->right->val);
    		findPaths(result, root->right, path + "->" + to_string(root->right->val));
    	}   		
    }

};