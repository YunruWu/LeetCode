/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
 */

// iterative solution DFS
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        stack<TreeNode*> s;
        stack<int> currentSum;
        s.push(root);
        currentSum.push(root->val);
		int sum = 0;
		
        while (!s.empty()) {
        	TreeNode* temp = s.top();
        	int current = currentSum.top();
        	s.pop();
        	currentSum.pop();
        	if (!temp->left && !temp->right) {
        		sum += current;
        	}
        	else {
        		if (temp->left) {
        			s.push(temp->left);
        			currentSum.push(current * 10 + temp->left->val);
        		}
        		if (temp->right) {
        			s.push(temp->right);
        			currentSum.push(current * 10 + temp->right->val);
        		}
        	}
        }

        return sum;
    }
};


// recursive solution DFS
class Solution {
public:
	int result = 0;

    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        dfs(root, result);
        return result;
    }

    void dfs(TreeNode* root, int currentSum) {
    	currentSum = currentSum * 10 + root->val;
    	if (root->left) dfs(root->left, currentSum);
    	if (root->right) dfs(root->right, currentSum);
    	if (!root->left && !root->right) {
    		result += currentSum;
    	}
    }
};