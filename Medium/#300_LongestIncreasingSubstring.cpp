/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?
 */


// O(n^2)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        vector<int> dp(n, 1);
        int result = 1;

        for (int i = 1; i < n; i++) {
        	for (int j = 0; j < i; j++) {
        		if (nums[j] < nums[i]) {
        			dp[i] = max(dp[i], dp[j] + 1); // update whenever there is greater value
        		}
        	}

        	result = max(result, dp[i]);
        }

        return result;
    }
};


// O(nlogn) using binary search
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
        	if (result.empty() || nums[i] > result.back()) {
        		result.push_back(nums[i]);
        	}
        	else {
        		// binary search
        		int left = 0, right = result.size() - 1;
        		while (left < right) {
        			int mid = (left + right) / 2;
        			if (nums[i] <= result[mid]) {
        				right = mid;
        			}
        			else {
        				left = mid + 1;
        			}
        		}
        		result[left] = nums[i];
        	}
        }

        return result.size();
    }
};