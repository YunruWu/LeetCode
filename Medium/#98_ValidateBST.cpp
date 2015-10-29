/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 */

/* 需要注意的是，左子树的所有节点都要比根节点小，而非只是其左孩子比其小，右子树同样。
这是很容易出错的一点是，很多人往往只考虑了每个根节点比其左孩子大比其右孩子小。如下面非二分查找树，如果只比较节点和其左右孩子的关系大小，它是满足的。

      5
   /     \
 4      10
       /      \
     3        11
        if (root->left->val >= root->val && root->right->val <= root->val) {
         	return false;
        }
        else 
         	return isValidBST(root->left) && isValidBST(root->right);
*/


// Recursive solution
class Solution {
public:
	bool isValidBST(TreeNode* root) {
    	return isValidBST(root, NULL, NULL);
	}

	bool isValidBST(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
    	if(!root) return true;
    	if(minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val)
       		return false;
    	return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
	}

};


// In-order traversal solution
// If we use in-order traversal to serialize a binary search tree, 
// we can get a list of values in ascending order. 
// It can be proved with the definition of BST. 
// And here I use the reference of TreeNode pointer prev 
// as a global variable to mark the address of previous node in the list.
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = NULL;
        return validate(root, prev);
    }
    bool validate(TreeNode* node, TreeNode* &prev) {
        if (node == NULL) return true;
        if (!validate(node->left, prev)) return false;
        if (prev != NULL && prev->val >= node->val) return false;
        prev = node;
        return validate(node->right, prev);
    }
};