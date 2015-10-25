/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
 */

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        deque<TreeNode*> dq;
        vector<int> levelNodes;
        dq.push_back(root);
        int level = 0;
        while (!dq.empty()) {
        	for (int i = dq.size(); i > 0; i--) {
        		if (level % 2) {
        			TreeNode* temp = dq.front();
        			levelNodes.push_back(temp->val);
        			dq.pop_front();
        			if (temp->right) dq.push_back(temp->right);
        			if (temp->left) dq.push_back(temp->left);
        		}
        		else if (level % 2 == 0) {
        			TreeNode* temp = dq.back();
        			levelNodes.push_back(temp->val);
        			dq.pop_back();
        			if (temp->left) dq.push_front(temp->left);
        			if (temp->right) dq.push_front(temp->right);
        		}
        	}
        	level++;
        	result.push_back(levelNodes);
        	levelNodes.clear();
        }

        return result;
    }
};


// find position using size of of the queue
vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    if (root == NULL) {
        return vector<vector<int> > ();
    }
    vector<vector<int> > result;

    queue<TreeNode*> nodesQueue;
    nodesQueue.push(root);
    bool leftToRight = true;

    while ( !nodesQueue.empty()) {
        int size = nodesQueue.size();
        vector<int> row(size);
        for (int i = 0; i < size; i++) {
            TreeNode* node = nodesQueue.front();
            nodesQueue.pop();

            // find position to fill node's value
            int index = (leftToRight) ? i : (size - 1 - i);

            row[index] = node->val;
            if (node->left) {
                nodesQueue.push(node->left);
            }
            if (node->right) {
                nodesQueue.push(node->right);
            }
        }
        // after this level
        leftToRight = !leftToRight;
        result.push_back(row);
    }
    return result;
}