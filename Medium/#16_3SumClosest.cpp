/*
O(n^2)
 */

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() <= 2) return 0;
        // handle cases with only 3 numbers
        int result = nums[0] + nums[1] + nums[2];
        
        sort(nums.begin(), nums.end());
        int start = 0, end = nums.size() - 1;

        while (start < end) { 
        	// fix the first number
        	int a = nums[start], cur = start + 1, cur_end = end;
        	while (cur < cur_end) {
        		int b = nums[cur], c = nums[cur_end];
        		int sum = a + b + c;
        		if (sum == target) {
        			return sum;
        		}

        		if (sum > target) {
        			cur_end--;
        		}
        		else {
        			cur++;
        		}

        		if (abs(sum-target) <= abs(result-target)) {
        			result = sum;
        		}
        	}

        	// skip the duplicates to speed up the process
        	while (nums[start] == a && start < end) start++;
        }

        return result;
    }
};