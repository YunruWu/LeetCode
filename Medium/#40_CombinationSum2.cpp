/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
 */

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> solution;
        std::sort(candidates.begin(),candidates.end());
        backtrack(result, solution, candidates, target, 0);
        return result;
    }

    void backtrack(vector<vector<int>>& result, vector<int>& solution, vector<int>& candidates, int target, int start) {
    	if (target == 0) {
    		result.push_back(solution);
    		return;
    	}

    	for (int i = start; i < candidates.size() && candidates[i] <= target; i++) {
    	    if (i > start && candidates[i] == candidates[i-1]) continue; // excape duplicates
    		solution.push_back(candidates[i]);
    		backtrack(result, solution, candidates, target-candidates[i], i+1);
    		solution.pop_back();
    	}
    }
};