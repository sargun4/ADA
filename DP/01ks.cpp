
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public: 
    int knapSack(int W, int wt[], int val[], int n) { 
        vector<vector<int>> dp(n+1,vector<int>(W + 1, 0));
        
        for(int i=0;i<n+1;i++){
            for(int w=0;w<W+1;w++){
                if(i==0||w==0){
                    dp[i][w]=0;
                }else if(wt[i-1]>W){
                    dp[i][w]=dp[i-1][w];//skip
                }else{
                    int skip=dp[i-1][w];
                    int take=dp[i-1][w-wt[i-1]]+val[i-1];
                    dp[i][w]=max(take,skip);
                }
            }
        }
        return dp[n][W];
    }
};
// class Solution{
//     public:
//     //Function to return max value that can be put in knapsack of capacity W.
//     int solve(int W, int wt[], int val[], int i,vector<vector<int>>&dp) {
//         if(i==0||W==0){
//             return 0;
//         }
//         if(dp[i][W]!=-1){
//             return dp[i][W];
//         }
//         // int take=INT_MIN;
//         if(wt[i-1]>W){
//             int skip=solve(W,wt,val,i-1,dp);
//             return dp[i][W]=skip;
//         }else{
//             int take=solve(W-wt[i-1],wt,val,i-1,dp)+val[i-1];
//             int skip=solve(W,wt,val,i-1,dp);
//             return dp[i][W]=max(skip,take);
//         }

//     }
//     int knapSack(int W, int wt[], int val[], int n) { 
//         vector<vector<int>> dp(n+1,vector<int>(W + 1, -1));
//         return solve(W, wt, val, n,dp);
//     }
// };

