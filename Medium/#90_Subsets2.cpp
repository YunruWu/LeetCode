/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
 */


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    	std::sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        vector<int> subset;
        backtrack(result, subset, nums, 0);
        return result;
    }

    void backtrack(vector<vector<int>>& result, vector<int>& subset, vector<int>& nums, int start) {
    	result.push_back(subset);
    	for (int i = start; i < nums.size(); i++) {
    		if (i == start || nums[i] != nums[i-1]) {
    			subset.push_back(nums[i]);
    			backtrack(result, subset, nums, i+1);
    			subset.pop_back();
    		}
    	}
    }
};


/*
If we want to insert an element which is a dup, we can only insert it after the newly inserted elements from last step.
 */
vector<vector<int> > subsetsWithDup(vector<int> &S) {
    sort(S.begin(), S.end());
    vector<vector<int>> ret = {{}};
    int size = 0, startIndex = 0;
    for (int i = 0; i < S.size(); i++) {
        startIndex = i >= 1 && S[i] == S[i - 1] ? size : 0;
        size = ret.size();
        for (int j = startIndex; j < size; j++) {
            vector<int> temp = ret[j];
            temp.push_back(S[i]);
            ret.push_back(temp);
        }
    }
    return ret;
}
