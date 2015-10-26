/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
 */


// Recursive solution
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.empty()) return NULL;
        return construct(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1);
    }

    TreeNode* construct(vector<int>& postorder, int pstart, int pend, vector<int>& inorder, int istart, int iend) {
    	if (pstart > pend) return NULL;
    	TreeNode* root = new TreeNode(postorder[pend]);

    	int root_idx;
    	for (i = istart; i <= iend; i++) {
    		if (root->var == inorder[i]) {
    			root_idx = i;
    			break;
    		}
    	}

    	root->left = construct(postorder, pstart, pstart + (root_idx-istart), inorder, istart, root_idx-1);
    	root->left = construct(postorder, pend - (iend-root_idx), inorder, root_idx+1, iend);

    	return root;
    }
};


// Iterative solution
// 从右到左建树，如果inorder的当前last值和栈顶值相同，说明没有左孩子要处理，or右子数都已经处理完
// 不相同的话则说明有左孩子要处理
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.size() == 0)return NULL;
        TreeNode *p;
        TreeNode *root;
        stack<TreeNode *> stn;

        root = new TreeNode(postorder.back()); 
        stn.push(root); 
        postorder.pop_back(); 

        while(true)
        {
            if(inorder.back() == stn.top()->val) 
            {
                p = stn.top();
                stn.pop(); 
                inorder.pop_back(); 
                if(inorder.size() == 0) break;
                if(stn.size() && inorder.back() == stn.top()->val)
                	// if equal means no left child need to be handled
                    continue;
                // handle left child
                p->left = new TreeNode(postorder.back()); 
                postorder.pop_back();
                stn.push(p->left);
            }
            else 
            {
                p = new TreeNode(postorder.back());
                postorder.pop_back();
                stn.top()->right = p; 
                stn.push(p); 
            }
        }
        return root;
    }
};
