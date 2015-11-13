/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
 */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zeros = 0, ones = 0, twos = 0;

        for (int i = 0; i < num.size(); i++) {
        	if (nums[i] == 0) zeros++;
        	else if (nums[i] == 1) ones++;
        	else if (nums[i] == 2) twos++;
        }

        for (int i = 0; i < zeros; i++) {
        	nums[i] = 0;
        }

        for (int i = 0; i < ones; i++) {
        	nums[zeros+i] = 1;
        }

        for (int i = 0; i < twos; i++) {
        	nums[zeros+ones+i] = 2;
        }
    }
};


// one pass solution
// Maintain the tail index for red region, and head index for the blue region. Scan the whole array, 
// and swap the current element with either red tail or blue head respectively.
class Solution {
    public:
        void sortColors(vector<int>& nums) {
            int tail_red = 0;
            int head_blue = nums.size() - 1;
            int cur = 0;
            while( cur <= head_blue){
                if(nums[cur] == 0){
                    swap(nums[tail_red], nums[cur]);
                    tail_red ++;
                    cur ++;
                }else if (nums[cur] == 2){
                    swap(nums[head_blue], nums[cur]);
                    head_blue = head_blue - 1;
                }else
                    cur ++;
            }
        }
    };