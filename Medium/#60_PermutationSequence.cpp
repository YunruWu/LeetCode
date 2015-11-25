/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
 */

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums(n);
        int total = 1;
        for (int i = 0; i < n; i++) {
            nums[i] = i + 1;
            total *= (i + 1);
        }
        if (k == 0 || k > total) return "";
        
        k--;
        string result = "";
        int len = n;
        for (int i = 0; i < len; i++) {
            total /= n;
            int selected = k / total;
            result += (nums[selected] + '0');
            
            for (int j = selected; j < len - i - 1; j++) {
                nums[j] = nums[j+1];  // move forward elements after the selected one
            }
            
            k %= total;
            n--;
        }
        
        return result;
    }
};