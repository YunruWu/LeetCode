/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2       0       8
         /  \
         7   4
For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
 */


// Recursive solution
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left && right) return root;
        return left ? left : right;
    }
};


// Iterative solution using stack
class Solution {
public:
     void getPath(TreeNode *root, TreeNode *p, TreeNode *q, vector<TreeNode*> &path, vector<TreeNode *> &path1, vector<TreeNode*> &path2) {
         if (root == NULL) return;
         path.push_back(root);
         if (root == p) path1 = path;
         if (root == q) path2 = path;
         //找到两个节点后就可以退出了
         if (!path1.empty() && !path2.empty()) return;
         getPath(root->left, p, q, path, path1, path2);
         getPath(root->right, p, q, path, path1, path2);
         path.pop_back();
     }
     
     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
         vector<TreeNode*> path, path1, path2;
         getPath(root, p, q, path, path1, path2);
         TreeNode *res = root;
         int idx = 0;
         while (idx < path1.size() && idx < path2.size()) {
             if (path1[idx] != path2[idx]) break;
             else res = path1[idx++];
         }
         return res;
     }
 };