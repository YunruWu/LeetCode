/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int ans[n] = {0};
        ans[0] = nums[0];
        int maxSum = ans[0];

        for (int i = 1; i < n; i++) {
        	ans[i] = nums[i] + (ans[i-1] > 0 ? ans[i-1] : 0);
        	maxSum = max(maxSum, ans[i]);
        }

        return maxSum;
    }
};