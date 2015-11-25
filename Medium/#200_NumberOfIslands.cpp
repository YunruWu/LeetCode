/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3
 */

// DFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        if (grid.empty()) return result;
        int row = grid.size(), col = grid[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1') {
                    result++;
                    dfs_find_island(grid, i, j, row, col);
                }
            }
        }
        return result;
    }
    
    void dfs_find_island(vector<vector<char>>& grid, int i, int j, int row, int col) {
        grid[i][j] = '0';
        if (i < row - 1 && grid[i+1][j] == '1') {
            dfs_find_island(grid, i+1, j, row, col);
        }
        if (i > 0 && grid[i-1][j] == '1') {
            dfs_find_island(grid, i-1, j, row, col);
        }
        if (j < col - 1 && grid[i][j+1] == '1') {
            dfs_find_island(grid, i, j+1, row, col);
        }
        if (j > 0 && grid[i][j-1] == '1') {
            dfs_find_island(grid, i, j-1, row, col);
        }
    }
};


// BFS 
