/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
 */

// Recursive solution
lass Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> path;
        findPath(result, path, root, sum);
        return result;
    }

    void findPath(vector<vector<int>>& result, vector<int>& path, TreeNode* root, int sum) {
    	if (!root) return;
    	path.push_back(root->val);
    	if (!root->left && !root->right && root->val == sum) {
    		result.push_back(path);
    		//path.clear();
    	}
    	sum -= root->val;
    	if (root->left) findPath(result, path, root->left, sum);
    	if (root->right) findPath(result, path, root->right, sum);
    	path.pop_back();
    }
};


// Iterative Solution
// history stack records parents. 
// When a new node has been visited, pop the history stack until finding his parent.
class Solution
{
public:
    vector<vector<int> > pathSum( TreeNode *root, int sum )
    {

        vector< vector<int>> res;
        if ( root == NULL )
            return res;

        vector< TreeNode *> stack;
        vector< TreeNode *> history;
        vector< int> sumStack;
        TreeNode *cur;
        TreeNode *pre;
        int tmp = 0;
        stack.push_back( root );
        sumStack.push_back( 0 );

        while ( stack.size() ) {
            cur  = stack.back();
            stack.pop_back();

            while ( history.size() > 0 ) {
                pre = history.back();
                if ( pre->left == cur || pre->right == cur )
                    break;
                history.pop_back();
            }

            tmp = sumStack.back();
            sumStack.pop_back();    
            tmp = tmp + cur->val;
            if ( tmp  == sum && cur ->right == NULL && cur->left == NULL ) {
                vector< int> tmpv;
                for ( int i = 0; i < history.size(); ++i ) {
                    tmpv.push_back( history[i]->val );
                }
                tmpv.push_back(cur->val);
                res.push_back( tmpv );
                continue;
            }

            history.push_back( cur );
            if ( cur->right ) {
                stack.push_back( cur->right );
                sumStack.push_back( tmp );
            }
            if ( cur->left ) {
                stack.push_back(  cur->left );
                sumStack.push_back( tmp );
            }
        }
        return res;
    }
};