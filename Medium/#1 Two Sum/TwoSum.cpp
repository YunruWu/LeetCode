/*
O(n)
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> num_index;
        for (int i = 0; i < nums.size(); i++)
        { 
        	int second = target - nums[i];
        	if (num_index.find(second) != num_index.end())
        	{
        		// found the second number
        		result.push_back(num_index[second]);
        		result.push_back(i+1);
        		break;
        	}
        	else
        	{
        		num_index[nums[i]] = i + 1;		// fill in map
        	}
        }

        return result;
    }
};