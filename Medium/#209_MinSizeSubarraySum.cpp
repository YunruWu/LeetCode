/*
Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

click to show more practice.

More practice:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
 */


class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int minlen = n + 1, start = 0, end = 0, sum = 0;
        
        while (start < n && end < n) {
            while (sum < s && end < n) {
                sum += nums[end];
                end++;
            }
            
            while (sum >= s && start <= end) {
                minlen = min(minlen, end - start);
                sum -= nums[start];
                start++;
            }
        }
        
        return minlen == n + 1 ? 0 : minlen;
    }
};