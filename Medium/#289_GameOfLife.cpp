/*
According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state.

Follow up: 
Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?
 */

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.empty()) return;
        const int m = board.size();
        const int n = board[0].size();
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                check(board,i,j,i+1,j-1);
                check(board,i,j,i+1,j);
                check(board,i,j,i+1,j+1);
                check(board,i,j,i,j+1);
                if(board[i][j]>=5 && board[i][j]<=7) board[i][j]=1;
                else board[i][j]=0;
            }
        }
    }
private:
    void check(vector<vector<int>>& board, int i, int j, int a, int b) {
        const int m = board.size();
        const int n = board[0].size();
        if(a>=m || b<0 || b>=n) return;
        if(board[i][j]%2!=0) board[a][b]+=2;
        if(board[a][b]%2!=0) board[i][j]+=2;
    } 
};


// bit manipulation
// Since the board has ints but only the 1-bit is used, I use the 2-bit to store the new state. 
// At the end, replace the old state with the new state by shifting all values one bit to the right.
void gameOfLife(vector<vector<int>>& board) {
    int m = board.size(), n = m ? board[0].size() : 0;
    for (int i=0; i<m; ++i) {
        for (int j=0; j<n; ++j) {
            int count = 0;
            for (int I=max(i-1, 0); I<min(i+2, m); ++I)
                for (int J=max(j-1, 0); J<min(j+2, n); ++J)
                    count += board[I][J] & 1;
            if (count == 3 || count - board[i][j] == 3)
                board[i][j] |= 2;
        }
    }
    for (int i=0; i<m; ++i)
        for (int j=0; j<n; ++j)
            board[i][j] >>= 1;
}