/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
For example,

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.

 */


// O(m + n)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int i = 0, j = col - 1;
        
        while (i < row && j >= 0) {
            if (matrix[i][j] == target) return true;
            else if (target > matrix[i][j]) {
                i++;
            }
            else
                j--;
        }
        
        return false;
    }
};


// O(mlogn) binary search row by row
bool searchMatrix(vector<vector<int>>& matrix, int target) {
return searchMatrix(matrix, target, 0, matrix.size() - 1);
}

bool searchMatrix(vector<vector<int>>& matrix, int target, int top, int bottom) {
if (top > bottom)
    return false;

int mid = top + (bottom - top) / 2;
if (matrix[mid].front() <= target && target <= matrix[mid].back())
    if (searchVector(matrix[mid], target)) return true;

if (searchMatrix(matrix, target, top, mid - 1)) return true;
if (searchMatrix(matrix, target, mid + 1, bottom)) return true;

return false;
}

bool searchVector(vector<int>& v, int target) {
int left = 0, right = v.size() - 1;

while (left <= right) {
    int mid = left + (right - left) / 2;
    if (v[mid] == target)
        return true;
    if (v[mid] < target)
        left = mid + 1;
    else
        right = mid - 1;
}

return false;
}


/*
分治法，以矩形中点为基准，将矩阵拆分成左上，左下，右上，右下四个区域

若中点值 < 目标值，则舍弃左上区域，从其余三个区域再行查找

若中点值 > 目标值，则舍弃右下区域，从其余三个区域再行查找

时间复杂度递推式： T(n) = 3T(n/2) + c
 */
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // check bad input
    int m = matrix.size();
    if(m == 0)
        return false;
    int n = matrix[0].size();
    if(n == 0)
        return false;
    return binarySearch(matrix, target, 0, m-1, 0, n-1);
}

bool binarySearch(vector<vector<int>>& matrix, int target, 
int min_i, int max_i, 
int min_j, int max_j){
    if(min_i > max_i)
        return false;
    if(min_j > max_j)
        return false;
    int i = (min_i + max_i)/2;
    int j = (min_j + max_j)/2;

    int value = matrix[i][j];
    if(value == target)
        return true;
    else if(value < target)
    {
        return binarySearch(matrix, target, min_i, max_i, j+1, max_j)
        || binarySearch(matrix, target, i+1, max_i, min_j, j);
    }
    else
    {
        return binarySearch(matrix, target, min_i, max_i, min_j, j-1)
        || binarySearch(matrix, target, min_i, i-1, j, max_j);            
    }
}