/*
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
 
O(n)
 */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0;
        int i = 0, j = height.size() - 1;
        while (i < j) {
        	int h = min(height[i], height[j]);
        	result = max(result, (j - i) * h);

        	//skip lines at both ends that don't support a higher height
        	while (i < j && height[i] <= h) i++; 
        	while (i < j && height[j] <= h) j--;
        }

        return result;
    }
};