/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 */

// using hash table
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
        	if (mp.find(nums[i]) != mp.end()) {
        		mp[nums[i]]++;
        	}
        	else
        		mp[nums[i]]++;
        }

        for (auto iter = mp.begin(); iter != mp.end(); iter++) {
        	if (iter->second == 1) {
        		return iter->first;
        	}
        }
        
    }
};


// using bit manipulation
//  A^B^A=B and A XOR A = 0
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
        	result ^= nums[i];
        }
        return result;
    }
};