
vector<string> summaryRanges(vector<int>& nums) {
    const int size_n = nums.size();
    vector<string> res;
    if ( 0 == size_n) return res;

    for (int i = 0; i < size_n;) 
    {
        int start = i, end = i;
        while (end + 1 < size_n && nums[end+1] == nums[end] + 1) end++;
        if (end > start) 
        	res.push_back(to_string(nums[start]) + "->" + to_string(nums[end]));
        else 
        	res.push_back(to_string(nums[start]));
        i = end+1;
    }
    
    return res;
}


/*
O(n)
 */
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        std::vector<string> result;
        int n = nums.size();

        if (n == 0) return result;
        else if (n == 1) result.push_back(to_string(nums[0]));
        else
        {
        	int begin = 0, i = 0;
        	for (; i < n - 1; i++)
        	{
        		if (nums[i+1] != nums[i] + 1)
        		{
        			if (i - begin == 0)
        				result.push_back(to_string(nums[i]));
        			else
        				result.push_back(to_string(nums[begin]) + "->" + to_string(nums[i]));
        			begin = i + 1;
        		}
        	}
        	
        	if (i - begin == 0)
        		result.push_back(to_string(nums[i]));
        	else
        		result.push_back(to_string(nums[begin]) + "->" + to_string(nums[i]));
        }

        return result;
    }
};