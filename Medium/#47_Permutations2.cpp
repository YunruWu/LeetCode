/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
 */

class Solution {
public:
    void recursion(vector<int> num, int i, int j, vector<vector<int> > &res) {
        if (i == j-1) {
            res.push_back(num);
            return;
        }
        for (int k = i; k < j; k++) {
            if (i != k && num[i] == num[k]) continue;
            swap(num[i], num[k]);
            recursion(num, i+1, j, res);
        }
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        sort(num.begin(), num.end());
        vector<vector<int> >res;
        recursion(num, 0, num.size(), res);
        return res;
    }
};


//
class Solution {
public:

    void permuteUniqueHelper(int i, vector<int>& nums, vector<vector<int> >& result) {
        if (i == nums.size()) { result.emplace_back(nums); return; }
        unordered_set<int> st;
        for (int j = i; j < nums.size(); ++j) {
            if (st.count(nums[j]) == 1) { continue; }
            st.insert(nums[j]);
            std::swap(nums[i], nums[j]);
            permuteUniqueHelper(i + 1, nums, result);
            std::swap(nums[i], nums[j]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int> > result;
        permuteUniqueHelper(0, nums, result);
        return result;
    }
};