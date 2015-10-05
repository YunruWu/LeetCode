/*
O(n)
 */

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // handle empty vector
        if (nums.size() == 0)
        	return 0;

        int length = 0;			// could remove all numbers
        int temp = nums[0];
        for (int i = 0; i < nums.size(); i++){
        	if (nums[i] != val){
        		temp = nums[i];
        		nums[length] = temp;
        		length++;
        	}
        }

        return length;
    }
};