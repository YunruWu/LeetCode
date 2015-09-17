/*
O(n)
 */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, bool> appearance;

        for (int i = 0; i < n; i++)
        {
        	if (appearance.find(nums[i]) != appearance.end()) return true;
        	else appearance[nums[i]] = true;
        }

        return false;
    }
};


// solution with sorting
// O(nlogn)
bool containsDuplicate(vector<int>& nums) {

    // empty array or single element has no duplicate
    if( (nums.size() == 0) || (nums.size() == 1) ) return false;

    // sort array
    std::sort(std::begin(nums), std::end(nums));

    // search for duplicate
    for(int i = 0; i < nums.size()-1; i++)
       if(nums[i] == nums[i+1]) return true;

    return false;
}