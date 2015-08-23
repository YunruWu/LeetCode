/*
O(n)
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // handle empty vector
        if (nums.size() == 0)
        	return 0;

        int length = 1;			// at least length of 1
        int temp = nums[0];
        for (int i = 1; i < nums.size(); i++){
        	if (nums[i] != temp){
        		temp = nums[i];			// move the pointer to the new number
        		nums[length] = temp;
        		length++;
        	}
        }

        return length;
    }
};