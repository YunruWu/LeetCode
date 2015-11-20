/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
 */

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        int left = 0, right = nums.size() - 1;

        while (left < right) {
        	int mid = left + (right - left) / 2;
        	if (target <= nums[mid]) {
        		right = mid;
        	}
        	else {
        		left = mid + 1;
        	}
        }

        if (nums[left] != target) return result;
        else result[0] = left;

        right = nums.size() - 1;
        while (left < right) {
        	int mid = left + (right - left) / 2 + 1;
        	if (target < nums[mid]) {
        	    right = mid - 1;
        	}
        	else {
        	    left = mid;
        	}
        }
        result[1] = right;

        return result;

    }
};