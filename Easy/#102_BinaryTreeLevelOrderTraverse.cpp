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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);
        
        vector<int> level;
        TreeNode* first;
        while (!q.empty())
        {
        	int level_len = q.size();
        	for (int i = 0; i < level_len; i++)
        	{
        		first = q.front();
        		q.pop();
        		level.push_back(first->val);
        		if (first->left)
        			q.push(first->left);
        		if (first->right)
        			q.push(first->right);
        	}

        	result.push_back(level);
        	level.clear();
        }

        return result;
    }
};