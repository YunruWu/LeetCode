/*
Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.
 */

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode *ch[26];
    bool isKey;
    TrieNode() {
        isKey = false;
        for (int i = 0; i < 26; ++i)
        {
            ch[i] = NULL;
        }
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        TrieNode *temp = root;
        for (int i = 0; i < s.size(); i++) {
            int index = s[i] - 'a';
            if (temp->ch[index] == NULL) {
                temp->ch[index] = new TrieNode();
            }
            temp = temp->ch[index];
        }
        temp->isKey = true;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        TrieNode *temp = root;
        for (int i = 0; i < key.size(); i++) {
            int index = key[i] - 'a';
            if (temp->ch[index] == NULL) {
                return false;
            }
            temp = temp->ch[index];
        }
        return temp->isKey;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *temp = root;
        for (int i = 0; i < prefix.size(); i++) {
            int index = prefix[i] - 'a';
            if (temp->ch[index] == NULL) {
                return false;
            }
            temp = temp->ch[index];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");