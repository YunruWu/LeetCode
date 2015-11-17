/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();

        int end = 1;
        for (int i = 2; i < nums.size(); i++) {
        	if (nums[i] == nums[end-1]) continue;
        	else if (nums[i] == nums[end] && nums[i] == nums[end-1]) end++;
        	else {
        	    end++;
        		nums[end] = nums[i];
        	}
        	/*
        	if(!(A[i] == A[rear] && A[i] == A[rear -1])){
                A[++rear] = A[i];
            }
        	 */
        }

        return end + 1;
    }
};


// Just go through the numbers and include those in the result that haven't been included twice already.
int removeDuplicates(vector<int>& nums) {
    int i = 0;
    for (int n : nums)
        if (i < 2 || n > nums[i-2])
            nums[i++] = n;
    return i;
}


// at most k times
int removeDuplicates(int A[], int n, int k) {

            if (n <= k) return n;

            int i = 1, j = 1;
            int cnt = 1;
            while (j < n) {
                if (A[j] != A[j-1]) {
                    cnt = 1;
                    A[i++] = A[j];
                }
                else {
                    if (cnt < k) {
                        A[i++] = A[j];
                        cnt++;
                    }
                }
                ++j;
            }
            return i;
}