/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

Calling next() will return the next smallest number in the BST.

Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

 */

class BSTIterator {
public:
    stack<TreeNode*> s;

    BSTIterator(TreeNode *root) {
        while (root) {
        	s.push(root);
        	root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* temp = s.top();
        s.pop();
        while (temp->right) {
        	s.push(temp->right);
        	temp->right = temp->right->left;
        }
        return temp->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */


class BSTIterator {
public:
    stack<TreeNode*> stk;
    int nextmin;
    BSTIterator(TreeNode *root) {
        while(root)
        {
            stk.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(!stk.empty())
        {
            TreeNode* top = stk.top();
            stk.pop();
            nextmin = top->val;
            TreeNode* cur = top->right;
            if(cur)
            {
                stk.push(cur);
                cur = cur->left;
                while(cur)
                {
                    stk.push(cur);
                    cur = cur->left;
                }
            }
            return true;
        }
        else
            return false;
    }

    /** @return the next smallest number */
    int next() {
        return nextmin;
    }
};