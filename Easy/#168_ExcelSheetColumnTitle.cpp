/*
O(n)
 */

class Solution {
public:
    string convertToTitle(int n) {
        string result;
        while (n)
        {
        	result = (char)((n-1) % 26 + 'A') + result;
        	n = (n-1) / 26;  //注意－1
        }

        return result;
    }
};