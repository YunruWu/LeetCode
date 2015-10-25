/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

For example:
Given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
You should return [1, 3, 4].
 */

// modified preorder traversal, DFS recursion
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        traverse(root, 1, result);
        return result;
    }

    void traverse(TreeNode* root, int level, vector<int>& result) {
    	if (!root) return;
    	if (result.size() < level) {  
    		result.push_back(root->val);
    	}
    	traverse(root->right, level+1, result);
    	traverse(root->left, level+1, result);
    }
};


// BFS + queue
// Using a queue mQ to perform level order traversal. 
// In the beginning of a level traversal, the last element is pushed into result array ret.
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
        	result.push_back(q.back()->val);
        	//for (int i = 0; i < q.size(); i++) {
        	for (int i = q.size(); i > 0; i--) {
        		TreeNode* temp = q.front();
        		q.pop();
        		if (temp->left) q.push(temp->left);
        		if (temp->right) q.push(temp->right);
        	}
        }

        return result;
    }

};