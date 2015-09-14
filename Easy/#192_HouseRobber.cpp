/*
O(n)
 */

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        else if (n == 1) return nums[0];
        else
        {
        	vector<int> maxValue(n);
        	maxValue[0] = nums[0];
        	maxValue[1] = max(nums[0], nums[1]);
        	for (int i = 2; i < n; i++)
        	{
        		maxValue[i] = max(maxValue[i-2] + nums[i], maxValue[i-1]);
        	}

        	return maxValue[n-1];
        }
    }
};


class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        else if (n == 1) return nums[0];
        else
        {
        	int max1 = nums[0];
        	int max2 = max(nums[0], nums[1]);
        	for (int i = 2; i < n; i++)
        	{
        		swap(max1, max2);
        		max2 = max(max2 + nums[i], max1);
        	}

        	return max2;
        }
    }
};