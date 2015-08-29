/*
O(n)
 */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int total = m + n - 1, i = m - 1, j = n - 1;
        while (j >= 0)  // j = -1 , no need to excute loop.
        {
            if (i < 0 || nums1[i] < nums2[j])   // nums1 is empty or nums1 < nums2
            {   
                nums1[total] = nums2[j];
                j--;
            }
            else 
            {
                nums1[total] = nums1[i];
                i--;
            }

            total--;
        }
    }
};