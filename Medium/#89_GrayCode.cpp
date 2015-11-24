/*
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
 */

// 第n位的格雷码由两部分构成，一部分是n-1位格雷码，再加上 1<<(n-1)和n-1位格雷码的逆序的和。
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        int temp = 1 << n;
        for (int i = 0; i < temp; i++) {
            result.push_back((i >> 1) ^ i);
        }
        return result;
    }
};


//
vector<int> grayCode(int n) {  
        // Start typing your C/C++ solution below  
        // DO NOT write int main() function  
        vector<int> res;  
        res.push_back(0);  
        int highbit = 0;  
        while(n--)  
        {  
            highbit = res.size();  
            for(int i= res.size()-1; i >= 0; i--)  
                res.push_back(highbit|res[i]);  
        }  
        return res;  
    }  


