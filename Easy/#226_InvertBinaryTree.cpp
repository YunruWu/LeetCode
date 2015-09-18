/*
O(n)
 */
// iterative solution 1
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        stack<TreeNode*> st;
        st.push(root);

        TreeNode* p;
        while (!st.empty())
        {
        	p = st.top();
        	st.pop();

        	if (p) 
        	{
        		st.push(p->left);
        		st.push(p->right);
        		swap(p->left, p->right);
        	}
        }

        return root;
    }
};


// iterative solution 2
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return root;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            if(node->left != NULL || node->right != NULL) {
                TreeNode* temp = node->left;
                node->left = node->right;
                node->right = temp;
            }
            if(node->left != NULL)
                q.push(node->left);
            if(node->right != NULL)
                q.push(node->right);
            q.pop();
        }
        return root;
    }
};


// recursive solution 1
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return root;

        if(root->left == NULL && root->right == NULL)
            return root;

        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        if(root->left != NULL)    
            invertTree(root->left);

        if(root->right != NULL)
            invertTree(root->right);

        return root;
    }
};


// recursive solution 2
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
    	if (root) {
        	invertTree(root->left);
        	invertTree(root->right);
        	swap(root->left, root->right);
    	}
    	
    	return root;
    }
};