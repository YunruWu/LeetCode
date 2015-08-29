/*
O(n)
 */

class Solution {
public:
    int lengthOfLastWord(string s) {
        // handle empty string
        if (s == "") return 0;
        
        int len = s.length();
        int i = len - 1;
        while (i >= 0 && s[i] == ' ')	// mark the index of the first non-space character as end
            i--;
            
        int end = i;
        while (i >= 0 && s[i] != ' ')
            i--;
        
        return end - i;
    }
};