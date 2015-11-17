/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
 */

// O(logm + logn)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low = 0, high = matrix.size() - 1;

        while (low < high) {
        	int mid = low + (high - low) / 2;
        	if (target < matrix[mid][0]) {
        		high = mid;
        	}
        	else if (matrix[mid][0] <= target && target < matrix[mid+1][0]){
        		low = mid;
        		break;
        	}
        	else {
        	    low = mid + 1;
        	}
        }
        
        int left = 0, right = matrix[low].size() - 1;
        while (left <= right) {
        	int mid = left + (right - left) / 2;
        	if (target < matrix[low][mid]) {
        		right = mid - 1;
        	}
        	else if (target > matrix[low][mid])
        		left = mid + 1;
        	else
        	    return true;
        }

        return false;
    }
};


// treat matrix as array
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    // treat the matrix as an array, just taking care of indices
    // [0..n*m]
    // (row, col) -> row*n + col
    // i -> [i/n][i%n]
    if(matrix.empty() || matrix[0].empty())
    {
        return false;
    }
    int m = matrix.size(), n = matrix[0].size();
    int start = 0, end = m*n - 1;
    while(start <= end)
    {
        int mid = start + (end - start)/2;
        int e = matrix[mid/n][mid%n];
        if(target < e)
        {
            end = mid - 1;
        }
        else if(target > e)
        {
            start = mid + 1;
        }
        else
        {
            return true;
        }
    }
    return false;
}