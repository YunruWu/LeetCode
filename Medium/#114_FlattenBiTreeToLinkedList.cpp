/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
click to show hints.

Hints:
If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.
 */

/*
(1) store the right child (we call R)
(2) find the right-most node of left child
(3) set R as the right-most node's right child.
(4) set left child as the right child
(5) set the left child NULL
(6) set current node to current node's right child.
(7) iterate these steps until all node are flattened.
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;

        while (root) {
        	if (root->left) {
        		TreeNode* temp = root->left;
        		while (temp->right) {
        			temp = temp->right;
        		}
        		temp->right = root->right;
        		root->right = root->left;
        		root->left = NULL;
        	}
        	root = root->right;
        }
    }
};