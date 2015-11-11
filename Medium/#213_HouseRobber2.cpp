/*
After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
 */


/*
the solution is now the maximum of

Rob houses 0 to n - 2;
Rob houses 1 to n - 1.
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n ? nums[0] : 0;
        return max(robber(nums, 0, n-2), robber(nums, 1, n-1));
    }

    int robber(vector<int>& nums, int start, int end) {
    	int maxMoney = 0, last = 0;
    	for (int i = start; i <= end; i++) {
    		int temp = max(last+nums[i], maxMoney);
    		last = maxMoney;
    		maxMoney = temp;
    	}

    	return maxMoney;
    }
};