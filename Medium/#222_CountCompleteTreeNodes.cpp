/*
Given a complete binary tree, count the number of nodes.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
 */

//满二叉树有一个性质是节点数等于2^h-1,h为高度，
//所以可以这样判断节点的左右高度是不是一样，
//如果是一样说明是满二叉树，就可以用刚才的公式，如果左右不相等就递归计算左右节点。
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int hl=0, hr=0;
        TreeNode* l=root, *r=root;

        while (l) {
        	hl++;
        	l = l->left;
        }

        while (r) {
        	hr++;
        	r = r->right;
        }

        if (hl == hr) return (1<<hl) - 1; // 1<<h1 faster than pow()

        return 1 + countNodes(root->left) + countNodes(root->right);

    }
};



// TLE
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int result;
        queue<TreeNode*> level;
        level.push(root);

        while (!level.empty()) {
        	TreeNode* temp = level.front();
        	level.pop();
        	result++;
        	if (temp->left) level.push(temp->left);
        	if (temp->right) level.push(temp->right);
        }
        return result;
    }
};