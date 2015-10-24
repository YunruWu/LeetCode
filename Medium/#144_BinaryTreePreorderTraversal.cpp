/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

Note: Recursive solution is trivial, could you do it iteratively?
 */

// Recursive solution
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorder(root, result);
        return result;
    }

    void preorder(TreeNode* root, vector<int>& result) {
    	if (!root) return;
    	result.push_back(root->val);
    	preorder(root->left, result);
    	preorder(root->right, result);
    }
};


// Iterative solution using stack
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> toVisit;
        TreeNode* current = root;
        while (current || !toVisit.empty()) {
        	if (current) {
        		result.push_back(current->val);
        		if (current->right) {
        			toVisit.push(current->right);
        		}
        		current = current->left;
        	}
        	else {
        		current = toVisit.top();
        		toVisit.pop();
        	}
        }

        return result;
    }
};


// Morris traversal solution
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* curNode = root;
    	vector<int> nodes;
    	while (curNode) {
        	if (curNode -> left) {
            	TreeNode* predecessor = curNode -> left;
            	while (predecessor -> right && predecessor -> right != curNode)
                	predecessor = predecessor -> right;
            	if (!(predecessor -> right)) {
            		nodes.push_back(curNode -> val);
                	predecessor -> right = curNode;
                	curNode = curNode -> left;
            	}
            	else {
                	predecessor -> right = NULL;
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