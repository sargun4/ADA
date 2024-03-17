#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
//memo 
    // At most k transactions. 
    int f(int idx, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>>& dp) {
        int n = prices.size(); 
        // Base case
        if (idx == n || cap == 0) // If we have reached the end of the prices array or no transactions are allowed, return 0.
            return 0; 
        if (dp[idx][buy][cap] != -1) // If the value is already calculated, return it.
            return dp[idx][buy][cap]; 
        if (buy == 1){//buy
            int take = -prices[idx] + f(idx + 1, 0, cap, prices, dp); // Buy the stock and move to the next day (buy = 0)
            int skip = f(idx + 1, 1, cap, prices, dp); // Skip buying the stock
            return dp[idx][buy][cap] = max(take, skip);
        } else { //sell
            int take = prices[idx] + f(idx + 1, 1, cap - 1, prices, dp); // Sell the stock and move to the next day with one fewer transaction available =>cap-1
            int skip = f(idx + 1, 0, cap, prices, dp); // Skip selling the stock
            return dp[idx][buy][cap] = max(take, skip);
        }
    }  
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1))); // Initialize dp array with -1
        return f(0, 1, k, prices, dp); // Start the recursive function with initial values
    }
};