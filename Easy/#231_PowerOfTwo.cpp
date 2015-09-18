/*
O(logn)
 */
class Solution {
public:
    bool isPowerOfTwo(int n) {
        while (n != 0 && n % 2 == 0)
        	n /= 2;

        if (n == 1) return true;
        else return false;
    }
};


// fancy solution
// The number has to be greater than zero, and just one of its bits is set. 
// Given n, computing n - 1 flips all the trailing 0s and the last 1. 
// So computing n & (n - 1) effectively clears the last 1 bit. 
// And in this case that should give us zero if n is a power of 2.
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && !(n&(n-1));
    }
};

