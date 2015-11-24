/*
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 */

// backtracking
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> permutation;
        vector<int> isChosen(nums.size(), 0);
        backtrack(result, permutation, nums, isChosen);
        return result;
    }
    
    void backtrack(vector<vector<int>>& result, vector<int>& permutation, vector<int>& nums, vector<int>& isChosen) {
        if (permutation.size() == nums.size()) {
            result.push_back(permutation);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (isChosen[i]) continue;
            permutation.push_back(nums[i]);
            isChosen[i] = 1;
            backtrack(result, permutation, nums, isChosen);
            permutation.pop_back();
            isChosen[i] = 0;
        }
    }
};


// other backtracking Solution
vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int> > ans;
    permutation(num, 0, ans);
    return ans;
}

void permutation(vector<int> &num, int begin, vector<vector<int> > &ans) {
    if (begin >= num.size()) {
        ans.push_back(num);
        return;
    }

    // every number chosen to be the begin once
    for (int i = begin; i < num.size(); ++i) {
        swap(num[begin], num[i]);
        permutation(num, begin+1, ans);
        swap(num[begin], num[i]);
    }
}


// dfs recursion
vector<vector<int> > permute(vector<int> &num) {
    vector<vector<int> > ans;
    dfs(num, ans);
    return ans;
}

void dfs(vector<int> &num, vector<vector<int>> &ans) {
    if (num.size() == 1) {
        vector<int> tmp(num.begin(), num.end());
        ans.push_back(tmp);
        return;
    }

    vector<vector<int> > ans1;
    vector<int> num1(num.begin()+1, num.end());
    dfs(num1, ans);

    for(int i = 0; i < ans.size(); ++i) {
        for(int j = 0; j <= ans[i].size(); ++j) {
            vector<int> tmp = ans[i];
            tmp.insert(tmp.begin()+j, num[0]);
            ans1.push_back(tmp);
        }
    }

    ans = ans1;
}