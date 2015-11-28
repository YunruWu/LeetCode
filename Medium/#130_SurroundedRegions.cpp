/*
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
 */


// BFS
class Solution {
public:
    void solve(std::vector<std::vector<char> > &board) {
        if (board.empty())
            return;
        rows = static_cast<int>(board.size());
        cols = static_cast<int>(board[0].size());
        if (rows <= 2 || cols <= 2)
            return;
        for (int col = 0; col < cols; ++col) {
            if (board[0][col] == 'O')
                solveBFS(board, 0, col);
            if (board[rows - 1][col] == 'O')
                solveBFS(board, rows - 1, col);
        }
        for (int row = 1; row < rows - 1; ++row) {
            if (board[row][0] == 'O')
                solveBFS(board, row, 0);
            if (board[row][cols - 1] == 'O')
                solveBFS(board, row, cols - 1);
        }
        for (int row = 0; row < rows; ++row)
            for (int col = 0; col < cols; ++col) {
                if (board[row][col] == 'O')
                    board[row][col] = 'X';
                else if (board[row][col] == 'N')
                    board[row][col] = 'O';
            }
    }
private:
    int rows, cols;
    void solveBFS(std::vector<std::vector<char> > &board, int i, int j) {
        board[i][j] = 'N';
        queue<pair<int, int>> que;
        que.push(make_pair(i, j));
        while (!que.empty()) {
            int row = que.front().first, col = que.front().second;
            que.pop();
            // no need to consider the peripheral border, so the condition
            // is i > 1, i < rows - 2, not i > 0, i < rows - 1.
            //
            // if use i > 0, i < rows - 1, BFS solution will be accepted too.
            if (row > 1 && board[row - 1][col] == 'O') {
                board[row - 1][col] = 'N';
                que.push(make_pair(row - 1, col));
            }
            if (row < rows - 2 && board[row + 1][col] == 'O') {
                board[row + 1][col] = 'N';
                que.push(make_pair(row + 1, col));
            }
            if (col > 1 && board[row][col - 1] == 'O') {
                board[row][col - 1] = 'N';
                que.push(make_pair(row, col - 1));
            }
            if (col < cols - 2 && board[row][col + 1] == 'O') {
                board[row][col + 1] = 'N';
                que.push(make_pair(row, col + 1));
            }
        }
    }
};



//DFS cause stack overflow
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        if (row == 0) return;
        int col = board[0].size();
        if (col == 0) return;
        //if (row == 0 || col == 0) return;
        
        // search the boundary for 'O's: top, right, bottom, left
        for (int i = 0; i < col; i++) {
            // top
            if (board[0][i] == 'O') {
                bfs(board, 0 , i);
            }
        }
        
            // bottom
        for (int i = 0; i < col; i++) {
            if (board[row-1][i] == 'O') {
                bfs(board, row-1, i);
            }
        }
        
        for (int i = 1; i < row-1; i++) {
            // left
            if (board[i][0] == 'O') {
                bfs(board, i , 0);
            }
        }
        
            // right
        for (int i = 1; i < row-1; i++) {
            if (board[i][col-1] == 'O') {
                bfs(board, i, col-1);
            }
        }
        
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == '1') {
                    board[i][j] = 'O';
                }
                else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
    
    void bfs(vector<vector<char>>& board, int row, int col) {
        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size()) 
            return;
            
        if (board[row][col] == 'O') {
            board[row][col] = '1';
            bfs(board, row-1, col);
            bfs(board, row+1, col);
            bfs(board, row, col-1);
            bfs(board, row, col+1);
        }
    }
};