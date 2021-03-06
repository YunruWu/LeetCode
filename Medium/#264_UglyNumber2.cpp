/*
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number.

Hint:

The naive approach is to call isUgly for every number until you reach the nth one. Most numbers are not ugly. Try to focus your effort on generating only the ugly ones.
An ugly number must be multiplied by either 2, 3, or 5 from a smaller ugly number.
The key is how to maintain the order of the ugly numbers. Try a similar approach of merging from three sorted lists: L1, L2, and L3.
Assume you have Uk, the kth ugly number. Then Uk+1 must be Min(L1 * 2, L2 * 3, L3 * 5).

 */

class Solution {
public:
    int nthUglyNumber(int n) {
       if (n == 1) return 1;
       int u2 = 0, u3 = 0, u5 = 0;
       vector<int> result(n);
       result[0] = 1;
       for (int i = 1; i < n; i++) {
       		result[i] = min(result[u2]*2, min(result[u3]*3, result[u5]*5));
       		if (result[i] == result[u2]*2) u2++;
       		if (result[i] == result[u3]*3) u3++;
       		if (result[i] == result[u5]*5) u5++;
       } 

       return result[n-1];
    }
};