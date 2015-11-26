/*
mplement int sqrt(int x).

Compute and return the square root of x.

这道题还有一种变形是给你一个数x，判断是否是一个完全平方数。基本思路一样，二分搜索1到x/2，结束条件是begin的平方大于x。

 */

class Solution {  
public:  
    int mySqrt(int x) {  
        if (x <= 1) {  
            return x;  
        }  
          
        int left = 1, right = x;  
          
        while (left <= right) {  
            int mid = left + ((right-left)>>1);  
            if(mid == x/mid) {  
                return mid;  
            }  
            else if(mid < x/mid) {  
                left = mid + 1;  
            }  
            else {  
                right = mid - 1;  
            }  
        }  
          
        return right;  
    }  
};  


//
int sqrt(int x) {
    unsigned int res = 0;
    for (int i = 15; i >= 0; i--)
    {
        if ((res + (1 << i)) * (res + (1 << i)) <= x)
            res += (1 << i);
    }
    return res;
}