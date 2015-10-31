/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

O(n) time, O(1) space
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit;
        if (prices.empty()) return max_profit;
        int n = prices.size();
        int curMin = prices[0];  // store the current minimum price

        for (int i = 1; i < n; i++) {
        	if (prices[i] < curMin) {
        		curMin = prices[i];
        	}
        	max_profit = max(max_profit, prices[i] - curMin);
        }

        return max_profit;
    }
};


/* Wrong answer
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int ans[n][n];
        int max = 0;

        for (int i = 0; i < n; i++) {
        	ans[i][i] = 0;
        }

        for (int i = 0; i < n; i++) {
        	for (int j = i + 1; j < n; j++) {
        		ans[i][j] = prices[j] - prices[i];
        		max = max(max, ans[i][j]);
        	}
        }

        return max;
    }
};
*/