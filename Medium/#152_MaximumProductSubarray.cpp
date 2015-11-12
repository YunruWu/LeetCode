/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
 */

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxResult = nums[0], curMin = nums[0], curMax = nums[0];

        for (int i = 1; i < n; i++) {
        	int a = min(nums[i]*curMin, nums[i]*curMax);
        	int b = max(nums[i]*curMin, nums[i]*curMax);
        	curMin = min(nums[i], a);
        	curMax = max(nums[i], b);
        	maxResult = max(maxResult, curMax);
        }

        return maxResult;
    }
};