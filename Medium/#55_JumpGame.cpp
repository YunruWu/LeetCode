/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
 */

// greedy
class Solution {
public:
bool canJump(vector<int>& nums) {
		int max_index = 0;
		for (int i = 0; i <= max_index; i++) {
			if (nums[i] + i > max_index) {
				if (nums[i] + i >= nums.size() - 1) {
					return true;
				}
				else {
					max_index = nums[i] + i;
				}
			}
		}
		
		return max_index == nums.size() - 1;
    }
};


