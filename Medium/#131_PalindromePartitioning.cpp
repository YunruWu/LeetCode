/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
 */

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> partition;
        backtrack(result, partition, s, 0);
        return result;
    }
    
    void backtrack(vector<vector<string>>& result, vector<string>& partition, string s, int start) {
        if (start == s.size()) { // not s.size()-1
            result.push_back(partition);
            return;
        }
        
        for (int i = start; i < s.size(); i++) {
            if (isPalindrome(s, start, i)) {
                partition.push_back(s.substr(start, i-start+1));
                backtrack(result, partition, s, i+1); // find next partition
                partition.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s, int start, int end) {
        while (start <= end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }
};