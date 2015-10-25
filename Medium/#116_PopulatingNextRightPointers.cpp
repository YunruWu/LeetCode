/*
Given a binary tree

    struct TreeLinkNode {
      TreeLinkNode *left;
      TreeLinkNode *right;
      TreeLinkNode *next;
    }
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
         1
       /  \
      2    3
     / \  / \
    4  5  6  7
After calling your function, the tree should look like:
         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \  / \
    4->5->6->7 -> NULL
 */

/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

// Iterative solution with O(1) space
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        while (root->left) {
        	TreeLinkNode* temp = root;
        	while (temp) {
        		temp->left->next = temp->right; // perfect binary tree
        		if (temp->next) {
        			temp->right->next = temp->next->left;
        		}
        		temp = temp->next; // move right
        	}
        	root = root->left;
        } 
    }
};


// Recursive solution with O(logn) space
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        if (root->left) root->left->next = root->right;
        if (root->right && root->next) root->right->next = root->next->left;
        connect(root->left);
        connect(root->right);
    }
};


// TLE
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        queue<TreeLinkNode*> q;
        q.push(root);

        while (!q.empty()) {
        	q.back()->next = NULL;
        	for (int i = q.size(); i > 0; i--) {
        		TreeLinkNode* temp = q.front();
        		q.pop();
        		if (!q.empty()) temp->next = q.front();
        		if (temp->left) q.push(temp->left);
        		if (temp->right) q.push(temp->right);
        	}
        }       
    }
};