/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
 */

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if (nums[0] != 0) return 0;
        int result = 1;
        int flag = 0;
        
        for (int i = 0; i < n - 1; i++) {
            if (nums[i+1] != nums[i] + 1) {
                result = nums[i] + 1;
                flag = 1;
            }
        }
        
        if (!flag) return nums[n-1]+1;
        else
            return result;
    }
};


// using XOR
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = nums.size();
        int i=0;

        for(int num:nums){
            result ^= num;
            result ^= i;
            // or result ^= (i ^ num);
            i++;
        }

        return result;
    }
};