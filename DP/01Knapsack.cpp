
#include <bits/stdc++.h>
using namespace std;
class Solution {
public: 
    int ks(int W, int wt[], int val[], int n,vector<vector<int>>&dp) {
        // Base Case
        if (n == 0 || W == 0)
            return 0; 
        // Check if the value is already memoized
        if (dp[n][W] != -1)
            return dp[n][W]; 
        // If weight of the nth item is more than Knapsack capacity W, then
        // this item cannot be included in the optimal solution
        if (wt[n - 1] > W)
            return dp[n][W] = ks(W, wt, val, n - 1,dp); 
        //else if wt is less than Knapsack capacity W
        // we can return the maximum of two cases:
        // (1) nth item included
        // (2) not included
        else
            return dp[n][W] = max(val[n - 1] + ks(W - wt[n - 1], wt,val,n-1,dp),
                                   ks(W, wt, val, n - 1,dp));
    } 
    int knapSack(int W, int wt[], int val[], int n){
        vector<vector<int>> dp(n+1,vector<int>(W + 1, -1));
        return ks(W, wt, val, n,dp);
    }
};


//Tabulation-topdown
//tab
class Solution {
public:
    int knapSack(int W, int wt[], int val[], int n) {
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
        for (int i = 0; i <= n; i++) {
            for (int w = 0; w <= W; w++) {
                if (i == 0 || w == 0) {
                    dp[i][w] = 0;
                } else if (wt[i - 1] > w) { //wt of ith item is greater than size of bag itself,so cant include
                    dp[i][w] = dp[i - 1][w];//skip
                } else {
                    int skip = 0 + dp[i - 1][w];
                    int take = val[i - 1] + dp[i - 1][w - wt[i - 1]];
                    dp[i][w] = max(take, skip);
                }
            }
        }
        return dp[n][W];
    }
};
 