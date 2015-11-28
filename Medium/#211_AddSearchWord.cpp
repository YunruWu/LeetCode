/*
Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

For example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.

click to show hint.

You should be familiar with how a Trie works. If not, please work on this problem: Implement Trie (Prefix Tree) first.

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

class WordDictionary {
public:

    WordDictionary() {
        root = new TrieNode();
    }
    
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *temp = root;
        for (int i = 0; i < word.size(); i++) {
            int index = word[i] - 'a';
            if (temp->ch[index] == NULL) {
                temp->ch[index] = new TrieNode();
            }
            temp = temp->ch[index];
        }
        temp->isKey = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        if (word.empty()) {
            return false;
        }
        return dfs_search(word, 0, root);
    }
    
private:
    TrieNode* root;
    
    bool dfs_search(string word, int start, TrieNode *cur) {
        if (!cur) return false;
        if (start == word.size()) return cur->isKey;
        
        if (word[start] == '.') {
            for (int i = 0; i < 26; i++) {
                if (cur->ch[i]) {
                    if (dfs_search(word, start+1, cur->ch[i])) {
                        return true;
                    }
                }
            }
        }
        else {
            int index = word[start] - 'a';
            if (cur->ch[index]) {
                return dfs_search(word, start+1, cur->ch[index]);
            }
        }
        
        return false;
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");