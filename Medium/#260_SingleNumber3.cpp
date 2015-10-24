/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
 */

/*
两个相等的数异或结果为0。因此，首次扫描数组，得到两个单独的数A、B的异或结果AxorB。
因为A和B不相等，因此AxorB一定不为0，且二进制位为1的位A和B一定不同。
任取AxorB中的一个二进制位，可以将原数组元素分成两组异或即得结果。

注意n&(~(n-1))表示取的n中的最后一位二进制位。

另外，&的优先级小于==的优先级。
 */

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int len = nums.size();  
        int AxorB = 0;  
        for(int i=0; i<len; i++){  
            AxorB ^= nums[i];  
        }

        int diff = AxorB & -AxorB;
        vector<int> result = {0, 0};
        for (int i : nums) {
        	if ((i & diff) == 0) {
        		result[0] ^= i;
        	}
        	else {
        		result[1] ^= i;
        	}
        }

        return result;
    }
};