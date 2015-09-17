/*
O(n)
 */

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> appearance;

        for (int i = 0; i < n; i++)
        {
        	if (appearance.find(nums[i]) != appearance.end() && (i-appearance[nums[i]]) <= k) return true;
        	else appearance[nums[i]] = i;
        }

        return false;
    }
};