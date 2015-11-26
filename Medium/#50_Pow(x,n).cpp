/*
Implement pow(x, n).
 */

// O(logn)
class Solution {
public:
    double myPow(double x, int n)  
    {  
        if (n == 0) return 1.0;  
        if (n < 0)  return 1.0 / pow(x,-n);  
        
        double half = pow(x, n>>1);  
        if (n % 2 == 0)  
            return half * half;  
        else  
            return half * half * x;  
    }  
};


//
double myPow(double x, int n) { 
    if(n==0) return 1;
    if(n<0){
        n = -n;
        x = 1/x;
    }
    return n%2==0 ? myPow(x*x, n/2) : x*myPow(x*x, n/2);
}


//
double myPow(double x, int n) { 
    if(n==0) return 1;
    double t = myPow(x,n/2);
    if(n%2) return n<0 ? 1/x*t*t : x*t*t;
    else return t*t;
}


/*
Consider the binary representation of n. 
For example, if it is "10001011", then x^n = x^(1+2+8+128) = x^1 * x^2 * x^8 * x^128. 
Thus, we don't want to loop n times to calculate x^n. T
o speed up, we loop through each bit, if the i-th bit is 1, then we add x^(1 << i) to the result. 
Since (1 << i) is a power of 2, x^(1<<(i+1)) = square(x^(1<<i)). 
The loop executes for a maximum of log(n) times.
 */
class Solution {  
public:  
    double pow(double x, int n) {  
        // Start typing your C/C++ solution below  
        // DO NOT write int main() function  
        if(n<0)  
        {  
            if(n==INT_MIN)  
                return 1.0 / (pow(x,INT_MAX)*x);  
            else  
                return 1.0 / pow(x,-n);  
        }  
        if(n==0)  
            return 1.0;  
        double ans = 1.0 ;  
        for(;n>0; x *= x, n>>=1)  
        {  
            if(n&1>0)  
                ans *= x;  
        }  
        return ans;  
    }  
};  