/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.
Example:
Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
Note:
The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.
 */


// O(logn) update and get sum
class NumArray {
public:
    NumArray(vector<int> &nums) {
        sz = nums.size();
        num = vector<int>(sz+1, 0);
        sum = vector<int>(sz+1, 0);
        for(int i=0; i<sz; i++) {
            update(i, nums[i]);
        }

    }

    void update(int idx, int val) {
        int oldv = num[idx+1];
        for(int i = idx+1; i<=sz; i+= (i&-i)) { // i & -i get the right most 1 in the binary i
            sum[i] = sum[i] - oldv + val;
        }
        num[idx+1] = val;
    }

    int sumRange(int i, int j) {
        return getSum(j+1) - getSum(i);
    }

    int getSum(int idx) {
        int ret = 0;
        for(int i=idx; i>0; i-=(i&-i)) {
            ret += sum[i];
        }
        return ret;
    }
private :
    int sz;
    vector<int> num;
    vector<int> sum;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);