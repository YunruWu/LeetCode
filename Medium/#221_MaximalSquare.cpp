/*
Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.
 */

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
    	if (!m) return 0;
    	int n = matrix[0].size();
    	vector<vector<int> > size(m, vector<int>(n, 0));
    	int maxsize = 0;

    	for (int j = 0; j < n; j++) {
        	size[0][j] = matrix[0][j] - '0';
        	maxsize = max(maxsize, size[0][j]);
    	}

    	for (int i = 1; i < m; i++) {
        	size[i][0] = matrix[i][0] - '0';
        	maxsize = max(maxsize, size[i][0]);
    	}

    	for (int i = 1; i < m; i++) {
        	for (int j = 1; j < n; j++) {
            	if (matrix[i][j] == '1') {
                	size[i][j] = min(size[i - 1][j - 1], min(size[i - 1][j], size[i][j - 1])) + 1;
                	maxsize = max(maxsize, size[i][j]);
            	}
        	}
    	}

    	return maxsize * maxsize;
    }
};


// improve to keep two columns
int maximalSquare(vector<vector<char>>& matrix) {
    int m = matrix.size();
    if (!m) return 0;
    int n = matrix[0].size();
    vector<int> pre(m, 0);
    vector<int> cur(m, 0);
    int maxsize = 0;
    for (int i = 0; i < m; i++) {
        pre[i] = matrix[i][0] - '0';
        maxsize = max(maxsize, pre[i]);
    }
    for (int j = 1; j < n; j++) {
        cur[0] = matrix[0][j] - '0';
        maxsize = max(maxsize, cur[0]);
        for (int i = 1; i < m; i++) {
            if (matrix[i][j] == '1') {
                cur[i] = min(cur[i - 1], min(pre[i - 1], pre[i])) + 1;
                maxsize = max(maxsize, cur[i]);
            }
        }
        swap(pre, cur);
        fill(cur.begin(), cur.end(), 0);
    }
    return maxsize * maxsize;
}


// improve by adding a 0 row on top of the dp vector
int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;
    int m = matrix.size(), n = matrix[0].size();
    vector<int> dp(m + 1, 0);
    int maxsize = 0, pre = 0;
    for (int j = 0; j < n; j++) {
        for (int i = 1; i <= m; i++) {
            int temp = dp[i];
            if (matrix[i - 1][j] == '1') {
                dp[i] = min(dp[i], min(dp[i - 1], pre)) + 1;
                maxsize = max(maxsize, dp[i]);
            }
            else dp[i] = 0; 
            pre = temp;
        }
    }
    return maxsize * maxsize;
}