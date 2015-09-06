/*
O(n)
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;

        int result = 0;
        unordered_map<char, int> cha_len;
        int begin = 0;
        
        for (int end = 0; end < s.length(); end++)
        {
        	int len = 0;
        	if (cha_len.find(s[end]) != cha_len.end())
        		begin = cha_len[s[end]] + 1;
      
        	len = end - begin + 1;
        	    
        	cha_len[s[end]] = end;
        	result = max(result, len);
        }

        return result;
    }
};