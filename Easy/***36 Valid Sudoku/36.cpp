/*
O(n^2)
 */

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {false}; // row[5][0] means whether number 1('0'+1) in row 5 has appeared
        bool col[9][9] = {false};
        bool block[3][3][9] = {false};

        for(int i = 0; i < 9; i++)
        {
        	for (int j = 0; j < 9; j++)
        	{
        		if (board[i][j] != '.')
        		{
        			// check the number in rows if it was used and set to true
        			if (row[i][board[i][j] - '1'])	
        				return false;
        			else
        				row[i][board[i][j] - '1'] = true;

        			// check the number in columns if it was used and set to true
        			if (col[j][board[i][j] - '1'])	
        				return false;
        			else
        				col[j][board[i][j] - '1'] = true;

        			// check the number in blocks if it was used and set to true
        			if (block[i/3][j/3][board[i][j] - '1'])
        				return false;
        			else
        				block[i/3][j/3][board[i][j] - '1'] = true; 
        		}
        	}
        }

        return true;
    }
};