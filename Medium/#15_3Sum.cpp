/*
O(n^2)
 */

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() <= 2) return {};
        
        sort(nums.begin(), nums.end());
        int start = 0, end = nums.size() - 1;

        while (start < end) { 
        	// fix the first number
        	int a = nums[start], cur = start + 1, cur_end = end;
        	while (cur < cur_end) {
        		int b = nums[cur], c = nums[cur_end];
        		int sum = a + b + c;
        		if (sum == 0) {
        			result.push_back({a, b, c});
        		}
        		if (sum <= 0) {
        			while (nums[cur] == b && cur < cur_end) cur++;
        		}
        		if (sum >= 0) {
        			while (nums[cur_end] == c && cur < cur_end) cur_end--;
        		}
        	}

        	while (nums[start] == a && start < end) start++;
        }

        return result;
    }
};