/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].

 */

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.size() == 0) return result;
        
        int rowend = matrix.size() - 1, colend = matrix[0].size() - 1;
        int rowstart = 0, colstart = 0;
        
        while (rowstart <= rowend && colstart <= colend) {
            for (int i = colstart; i <= colend; i++) {
                result.push_back(matrix[rowstart][i]);
            }
            rowstart++;
            
            for (int i = rowstart; i <= rowend; i++) {
                result.push_back(matrix[i][colend]);
            }
            colend--;
            
            if (rowstart <= rowend) { // handle one row and one column
                for (int i = colend; i >= colstart; i--) {
                    result.push_back(matrix[rowend][i]);
                }
            }
            rowend--;
            
            if (colstart <= colend) {
                for (int i = rowend; i >= rowstart; i--) {
                    result.push_back(matrix[i][colstart]);
                }
            }
            colstart++;
        }
        
        return result;
    }
};