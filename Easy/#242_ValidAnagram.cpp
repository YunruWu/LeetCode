// sorting solution
class Solution {
public:
    bool isAnagram(string s, string t) {
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        return s == t;
    }
};


// hash table
// This idea uses a hash table to record the times of appearances 
// of each letter in the two strings s and t. 
// For each letter in s, it increases the counter by 1 
// while for each letter in t, it decreases the counter by 1. 
// Finally, all the counters will be 0 if they two are anagrams of each other.
// O(n)
class Solution {
public:
    bool isAnagram(string s, string t) {
    	// handle different length
        if (s.length() != t.length()) return false;
        int n = s.length();
        int counts[26] = {0};
        for (int i = 0; i < n; i++) { 
            counts[s[i] - 'a']++;
            counts[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
            if (counts[i]) return false;
        return true;
    }
};
