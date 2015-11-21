/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.

Hint:

How many majority elements could it possibly have?
Do you have a better hint? Suggest it!
 */

// Moore Voting
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        int candidate1, candidate2;
        int count1 = 0, count2 = 0;
        
        for (int n : nums) {
            if (n == candidate1) {
                count1++;
            }
            else if (n == candidate2) {
                count2++;
            }
            else if (count1 == 0) {
                candidate1 = n;
                count1++;
            }
            else if (count2 == 0) {
                candidate2 = n;
                count2++;
            }
            else {
                count1--;
                count2--;
            }
        }
        
        count1 = count2 = 0;
        for (int n : nums) {
            if (n == candidate1) {
                count1++;
            }
            else if (n == candidate2) {
                count2++;
            }
        }
        
        if (count1 > nums.size() / 3) result.push_back(candidate1);
        if (count2 > nums.size() / 3) result.push_back(candidate2);
        return result;
    }
};