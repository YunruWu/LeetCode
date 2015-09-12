/*
O(log5(n))
 */

class Solution {
public:
    int trailingZeroes(int n) {
        int result = 0;
        while (n)
        {
        	result += n / 5;
        	// 25 have two 5 factors, 125 have three 5 factors
        	n /= 5;
        }

        return result;
    }
};