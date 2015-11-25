/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

prices = [1, 2, 3, 0, 2]
maxProfit = 3
transactions = [buy, sell, cooldown, buy, sell]
 */


/*
dp[i] means current max profit. isUsed means whether there is a operation in the previous day. lastUsedIndex means the last day which has a operation.

And for dp[i], basically there are two condition :

just keep the same, dp[i] = dp[i-1]

selling the stock in this day:

a: if isUsed = 0, dp[i] = max(dp[i-3] + prices[i] - prices[i-1], dp[lastUsedIndex] + prices[i] - prices[lastUsedIndex]);

b: if isUsed = 1, dp[i] = dp[i-1] + prices[i] - prices[i-1];
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int n = prices.size();
        vector<int> dp(n, 0);
        bool isRest = 0;
        int lastOperatedDay = -1;
        
        for (int i = 1; i < n; i++) {
            int difference = max(0, prices[i]-prices[i-1]);
            int cur;
            if (isRest == 0) {
                cur = i > 2 ? dp[i-3] + difference : difference;
                if (lastOperatedDay != -1) {
                    cur = max(cur, dp[lastOperatedDay] + prices[i] - prices[lastOperatedDay]);
                }
            }
            else {
                cur = dp[i-1] + difference;
            }
            
            if (cur <= dp[i-1]) {
                dp[i] = dp[i-1];
                isRest = 0;
            }
            else {
                dp[i] = cur;
                isRest = 1;
                lastOperatedDay = i;
            }
        }
        
        return dp[n-1];
    }
};


