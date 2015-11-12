/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.

 */

class NumArray {
    vector<int> given;
public:
    NumArray(vector<int> &nums) {
         if(nums.empty()) {
            given.push_back(0);
         }else{
             given = nums;
             given[0] = nums[0];
             int length = nums.size();
             for(int i = 1; i < length; ++i){
                given[i] = given[i - 1] + nums[i];
             }
         }
    }

    int sumRange(int i, int j) {
        return given[j] - given[i - 1];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);