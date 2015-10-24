/*
Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?

Hint:

Expected runtime complexity is in O(log n) and the input is sorted.
 */

// Binary Search
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0, right = n - 1;
        while (left <= right) {
        	int middle = (left + right) / 2;
        	if (citations[middle] > n - middle) {
        		right = middle - 1;
        	} 
        	else if (citations[middle] < n - middle) {
        		left = middle + 1;
        	}
        	else
        		return n - middle;
        }

        //return 0;
        return n - left; // handle [0]..
    }
};