/*
Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
 */

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, int> pat_mp;
        unordered_map<string, int> str_mp;

        stringstream ss(str);
        string word;
        int i = 0, n = pattern.size();

        // split string by space
        while (getline(ss, word, ' ')) {
        	if (i == n || pat_mp[pattern[i]] != str_mp[word]) {
        		return false;
        	}
        	else {
        		// if the same pattern, they will always have same pace
        		pat_mp[pattern[i++]] = str_mp[word] = i+1;
        	}
        }

        return i == n;  // false when two strings have different length;
    }
};