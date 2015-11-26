/*
Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".
 */


/*
We use a boolean vector dp[]. dp[i] is set to true if a valid word (word sequence) ends there. 
The optimization is to look from current position i back 
and only substring and do dictionary look up in case the preceding position j with dp[j] == true is found.
 */
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if (s.empty()) return false;
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        
        for (int i = 1; i <= n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j] && wordDict.find(s.substr(j, i-j)) != wordDict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[n];
    }
};