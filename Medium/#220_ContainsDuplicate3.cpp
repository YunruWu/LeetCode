/*
Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.
 */

// O(n)
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
        multiset<int> range;

        for (int i = 0; i < n; i++)
        {
        	if (i > k) {
        	    range.erase(nums[i-k-1]);
        	}
        	auto lb = range.lower_bound(nums[i] - t); // -t <= x - nums[i] <= t;
        	if (lb != range.end() && (*lb - nums[i]) <= t) return true;
        	
        	range.insert(nums[i]);
        }

        return false;
    }
};