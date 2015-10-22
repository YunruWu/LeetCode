/*
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?
 */

// Recursive solution
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }

    void inorder(TreeNode* root, vector<int>& result) {
    	if (!root) return;
    	inorder(root->left, result);
    	result.push_back(root->val);
    	inorder(root->right, result);
    }
};


// Iterative solution using stack
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> toVisit;
        TreeNode* current = root;
        while (current || !toVisit.empty()) {
        	if (current) {
        		toVisit.push(current);
        		current = current->left;
        	}
        	else {
        		current = toVisit.top();
        		toVisit.pop();
        		result.push_back(current->val);
        		current = current->right;
        	}
        }

        return result;
    }
};


// Morris traversal solution
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* curNode = root;
    	vector<int> nodes;
    	while (curNode) {
        	if (curNode -> left) {
            	TreeNode* predecessor = curNode -> left;
            	while (predecessor -> right && predecessor -> right != curNode)
                	predecessor = predecessor -> right;
            	if (!(predecessor -> right)) {
                	predecessor -> right = curNode;
                	curNode = curNode -> left;
            	}
            	else {
                	predecessor -> right = NULL;
                	nodes.push_back(curNode -> val);
                	curNode = curNode -> right;
            	}
        	}
        	else {
            	nodes.push_back(curNode -> val);
            	curNode = curNode -> right;
        	}
    	}
    	return nodes;
    }
};