/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
 */

class Solution {
public:
    int m, n;
    
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isExist(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool isExist(vector<vector<char>>& board, string word, int row, int col, int strpos) {
        if (row < 0 || col < 0 || row >= m || col >= n || board[row][col] == ' ' || board[row][col] != word[strpos]) {
            return false;
        }
        else if (strpos == word.size() - 1) {
            return true;
        }
        
        char temp = board[row][col];
        board[row][col] = ' ';
        strpos++;
        if (isExist(board, word, row+1, col, strpos) || isExist(board, word, row-1, col, strpos) || isExist(board, word, row, col+1, strpos) || isExist(board, word, row, col-1, strpos)) {
            return true;
        }
        board[row][col] = temp;
        return false;
    }
};