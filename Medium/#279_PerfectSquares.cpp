/*
Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
 */

// DP solution 
// O(nsqrt(n))
class Solution {
public:
    int numSquares(int n) {
        int ans[n+1] = {0};

        // for (int i = 0; i < n; i++) {
        // 	ans[i] = i;
        // }

        for (int i = 0; i <= n; i++) {
            ans[i] = i;
        	for (int j = 2; j*j <= i; j++) {
        		ans[i] = min(ans[i], ans[i - (j*j)] + 1);
        	}
        }

        return ans[n];
    }
};


// Math Solution
// O(sqrt(n))
class Solution 
{  
private:  
    int is_square(int n)
    {  
        int sqrt_n = (int)(sqrt(n));  
        return (sqrt_n*sqrt_n == n);  
    }

public:
    // Based on Lagrange's Four Square theorem, there 
    // are only 4 possible results: 1, 2, 3, 4.
    int numSquares(int n) 
    {  
        // If n is a perfect square, return 1.
        if(is_square(n)) 
        {
            return 1;  
        }

        // The result is 4 if n can be written in the 
        // form of 4^k*(8*m + 7).
        while ((n & 3) == 0) // n%4 == 0  
        {
            n >>= 2;  
        }
        if ((n & 7) == 7) // n%8 == 7
        {
            return 4;
        }

        // Check whether 2 is the result.
        int sqrt_n = (int)(sqrt(n)); 
        for(int i = 1; i <= sqrt_n; i++)
        {  
            if (is_square(n - i*i)) 
            {
                return 2;  
            }
        }  

        return 3;  
    }  
}; 