/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
 */

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            while (left < right && nums[left] == nums[left + 1]) left++;
            while (left < right && nums[right] == nums[right - 1]) right--;
        	int mid = left + (right - left) / 2;
        	if (target == nums[mid]) {
    			return true;
        	}

        	// there exists rotation; the middle element is in the left part of the array
        	if (nums[mid] > nums[right]) {
        		if (target < nums[mid] && target >= nums[left]) {
        			right = mid - 1;
        		}
        		else
        			left = mid + 1;
        	}
        	// there exists rotation; the middle element is in the right part of the array
        	else {
        		if (target > nums[mid] && target <= nums[right]) {
        			left = mid + 1;
        		}
        		else
        			right = mid - 1;
        	}
        }

        return false;
    }
};