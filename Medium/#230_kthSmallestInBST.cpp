/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?

Hint:

Try to utilize the property of a BST.
What if you could modify the BST node's structure?
The optimal runtime complexity is O(height of BST).
 */

// In-order traversal solution
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if (!root) return 0;
        vector<int> nodeValues;
        inorder(nodeValues, root);
        return nodeValues[k-1];
    }

    void inorder(vector<int>& nodeValues, TreeNode* root) {
    	if (!root) return;
    	inorder(nodeValues, root->left);
    	nodeValues.push_back(root->val);
    	inorder(nodeValues, root->right);
    }
};


// DFS in-order iterative
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode *> st;
        TreeNode *p = root;
        while(p || !st.empty())
        {
            while(p)
            {
                st.push(p);
                p = p->left;
            }
            p = st.top();
            if(--k == 0)
                return p->val;
            st.pop();
            p = p->right;
        }
    }
};


// DFS in-order recursive
class Solution {
public:
	int result = 0, num = 0;

    int kthSmallest(TreeNode* root, int k) {
        num = k;
        helper(root);
        return result;
    }

    void helper(TreeNode* root) {
    	if (root->left) helper(root->left);
    	num--;
    	if (num == 0) {
    		result = root->val;
    		return;
    	}
    	if (root->right) {
    		helper(root->right);
    	}
    }
};


// counting left tree nodes
int kthSmallest(TreeNode* root, int k) {
    if (!root) return 0;
    if (k==0) return root->val;

    int n=count_size(root->left);
    if (k==n+1) return root->val;

    if (n>=k){
        return kthSmallest(root->left, k);
    }
    if (n<k){
        return kthSmallest(root->right, k-n-1);
    }

}

int count_size(TreeNode* root){
    if (!root) return 0;
    return 1+count_size(root->left)+count_size(root->right);

}
