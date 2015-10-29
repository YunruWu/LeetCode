/*
Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.

For example, you may serialize the following tree

    1
   / \
  2   3
     / \
    4   5
as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.

 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        if (!root) return result;
        queue<TreeNode*> q;
        q.push(root);
        while (!s.empty()) {
        	if (q.front() == NULL) {
        		result += "#,";
        	}
        	else {
        		q.push(q.front()->left);
        		q.push(q.front()->right);
        	}
        	result += to_string(q.front()->val) + ",";
        	q.pop();
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.size() == 0) return NULL;
        stringstream ss(data);
        vector<string> datas;
        while (getline(ss, temp, ',')) {
        	datas.push_back(temp);
        }

        TreeNode* root = new TreeNode(stoi(datas[0]));
        queue<TreeNode*> q;
        q.push(root);
        int pounds = 0;

        while (!q.empty()) {
        	TreeNode* temp = q.front();
        	q.pop();
        	if (datas[2*(i-pounds)+1] == '#') {
        		temp->left = NULL;
        		pounds++;
        	}
        	else {
        		temp->left = new TreeNode(stoi(datas[2*(i-pounds)+1]));
        		q.push(temp->left);
        	}

        	if (datas[2*(i-pounds)+2] == '#') {
        		temp->right = NULL;
        		pounds++;
        	}
        	else {
        		temp->right = new TreeNode(stoi(datas[2*(i-pounds)+2]));
        		q.push(temp->right);
        	}
        	//q.push(temp->right);
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

class Codec {
public:

    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }

private:

    void serialize(TreeNode* root, ostringstream& out) {
        if (root) {
            out << root->val << ' ';
            serialize(root->left, out);
            serialize(root->right, out);
        } else {
            out << "# ";
        }
    }

    TreeNode* deserialize(istringstream& in) {
        string val;
        in >> val;
        if (val == "#")
            return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};



// Iterative solution
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        string str;
        while (!q.empty()) {
            if (q.front() == nullptr) {
                str = str + "#,";
            } else {
                q.push(q.front()->left);
                q.push(q.front()->right);
                str = str + to_string(q.front()->val) + ",";
            }
            q.pop();
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root = nullptr;
        queue<TreeNode**> q;
        q.push(&root);
        string::iterator first = data.begin();
        while (first != data.end()) {
            TreeNode** pp = q.front();
            if (*first == '#') {
                // *pp = nullptr;
                advance(first, 2);
            } else {
                string::iterator last = find(first, data.end(), ',');
                int val = stoi(string(first, last));
                *pp = new TreeNode(val);
                q.push(&((*pp)->left));
                q.push(&((*pp)->right));
                first = next(last);
            }
            q.pop();
        }
        return root;
    }
};