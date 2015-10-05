class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size() < 4) return {};

        sort(nums.begin(), nums.end());
        
        int i = 0;
        while (i < nums.size() - 3) {
        	// set a new target for 3 sum
        	int temp = target - nums[i];
        	int fixed = nums[i];

        	int start = i + 1, end = nums.size() - 1;

        	while (start < end) { 
        		// fix the first number
        		int a = nums[start], cur = start + 1, cur_end = end;
        		while (cur < cur_end) {
        			int b = nums[cur], c = nums[cur_end];
        			int sum = a + b + c;
        			if (sum == temp) {
        				result.push_back({fixed, a, b, c});
        			}
        			if (sum <= temp) {
        				while (nums[cur] == b && cur < cur_end) cur++;
        			}
        			if (sum >= temp) {
        				while (nums[cur_end] == c && cur < cur_end) cur_end--;
        			}
        		}

        		while (nums[start] == a && start < end) start++;
        	}

        	while (nums[i] == fixed) i++;
        }

        return result;
    }
};