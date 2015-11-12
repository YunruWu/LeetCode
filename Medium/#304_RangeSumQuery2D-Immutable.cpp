/*
Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).

Range Sum Query 2D
The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.

Example:
Given matrix = [
  [3, 0, 1, 4, 2],
  [5, 6, 3, 2, 1],
  [1, 2, 0, 1, 5],
  [4, 1, 0, 1, 7],
  [1, 0, 3, 0, 5]
]

sumRegion(2, 1, 4, 3) -> 8
sumRegion(1, 1, 2, 2) -> 11
sumRegion(1, 2, 2, 4) -> 12
Note:
You may assume that the matrix does not change.
There are many calls to sumRegion function.
You may assume that row1 ≤ row2 and col1 ≤ col2.
 */

class NumMatrix {
public:
NumMatrix(vector<vector<int>> &matrix) {
    sum_matrix = matrix;
    if(matrix.empty()) return;

    for(int i = 0; i < matrix.size() - 1; ++i)
        sum_matrix[i + 1][0] += sum_matrix[i][0];

    for(int j = 0; j < matrix[0].size() - 1; ++j)
        sum_matrix[0][j + 1] += sum_matrix[0][j];
    
    for(int i = 1; i < matrix.size(); ++i)
    {
        for(int j = 1; j < matrix[0].size(); ++j)
        {
            sum_matrix[i][j] += sum_matrix[i - 1][j] + sum_matrix[i][j - 1] - sum_matrix[i - 1][j - 1];
        }
    }
}

int sumRegion(int row1, int col1, int row2, int col2) {
    if(sum_matrix.empty()) return 0;
    int all = sum_matrix[row2][col2];
    int left = (col1 == 0) ? 0 : sum_matrix[row2][col1 - 1];
    int top = (row1 == 0) ? 0 : sum_matrix[row1 - 1][col2];
    int mid = (row1 == 0 || col1 == 0) ? 0 : sum_matrix[row1 - 1][col1 - 1];
    return all - left - top + mid;

}
private:
	vector<vector<int>> sum_matrix;//(i, j): (0,0)(i,j) sum
};

// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);