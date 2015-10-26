/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
 */

// iterative solution O(n)
// 1) Keep pushing the nodes from the preorder into a stack (and keep making the tree by adding nodes to the left of the previous node) until the top of the stack matches the inorder.
// 2) At this point, pop the top of the stack until the top does not equal inorder (keep a flag to note that you have made a pop).
// 3) Repeat 1 and 2 until preorder is empty. The key point is that whenever the flag is set, insert a node to the right and reset the flag.
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = NULL;
        if (preorder.empty()) return root;
        root = new TreeNode(preorder[0]);

        stack<TreeNode*> s;
        s.push(root);
        int inorder_index = 0;

        for (int i = 1; i < preorder.size(); i++) {
        	TreeNode* cur = s.top();
        	if (s.top()->val != inorder[inorder_index]) { // cur->val is not correct
        		cur->left = new TreeNode(preorder[i]);
        		s.push(cur->left);
        	}
        	else {
        		while (!s.empty() && (s.top()->val == inorder[inorder_index])) {
        			cur = s.top();
        			s.pop();
        			inorder_index++;
        		}
        		if (inorder_index < inorder.size()) {
        			cur->right = new TreeNode(preorder[i]);
        			s.push(cur->right);
        		}
        	}
        }

        return root;
    }
};


// recursive solution
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return NULL;
        return construct(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }

    TreeNode* construct(vector<int>& preorder, int pstart, int pend, vector<int>& inorder, int istart, int iend) {
    	if (pstart > pend) return NULL;
    	TreeNode* root = new TreeNode(preorder[pstart]);

    	int root_idx;
    	for (int i = istart; i <= iend; i++) {
    		if (inorder[i] == root->val) {
    			root_idx = i;
    			break; // find the position of current root in inorder array then break
    		}
    	}

    	root->left = construct(preorder, pstart+1, pstart + (root_idx - istart), inorder, istart, root_idx-1);
    	root->right = construct(preorder, pend - (iend - root_idx) + 1, pend, inorder, root_idx+1, iend);
    	
    	return root;
    }
};