/*
O(n)
 */

class Solution {
public:
    bool isPalindrome(string s) {
    	// two pointers
        int start = 0, end = s.length() - 1;
        while (start <= end) 
        {
            if (!isalnum(s[start])) start++;
            else if (!isalnum(s[end])) end--;
            else if (tolower(s[start])!=tolower(s[end])) return false;
            else
            {
                start++;
                end--;
            }
        }
    
        return true;
    }
};