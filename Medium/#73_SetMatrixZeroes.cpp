/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
 */

/*
In the first phase, use matrix elements to set states in a top-down way. 
In the second phase, use states to set matrix elements in a bottom-up way.
 */
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int flag = 0;

        for (int i = 0; i < m; i++) {
        	if (matrix[i][0] == 0) flag = 1;
        	for (int j = 1; j < n; j++) {
        		if (matrix[i][j] == 0) {
        			matrix[i][0] = matrix[0][j] = 0;
        		} 
        	}
        }

        for (int i = m - 1; i >= 0; i--) {
        	for (int j = n - 1; j >= 1; j--) {
        		if (matrix[i][0] == 0 || matrix[0][j] == 0) {
        			matrix[i][j] = 0;
        		} 
        	}
        	if (flag) matrix[i][0] = 0;
        }
    }
};