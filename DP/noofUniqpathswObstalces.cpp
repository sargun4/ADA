
#include <bits/stdc++.h>
using namespace std;
int mod=(1e9+7);
//memo
// class Solution {
// public:
//     int solve(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&dp) {
//         if(i>=0 && j>=0 && grid[i][j]==0) return 0;
//         if(i==0 && j==0) return 1;//reached
//         if(i<0||j<0)return 0;
//         //if already computed then return the value else compute and store it in dp array
//         if(dp[i][j]!=-1) return dp[i][j];
//         int up=solve(i-1,j,grid,dp);
//         int left=solve(i,j-1,grid,dp);
//         return dp[i][j]=(up+left)%mod;
//     }
//     int uniquePaths(int n, int m, vector<vector<int>> &grid){
//         vector<vector<int>>dp(n,vector<int>(m,-1));
//         return solve(n-1,m-1,grid,dp);
//     }
// };

//tab
class Solution {
public:
    int uniquePaths(int n, int m, vector<vector<int>> &grid){
        int dp[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0) dp[i][j]=0;
                else if(i==0 && j==0) dp[i][j]=1;
                else{
                    int up=0;int left=0;
                    if(i>0) up=dp[i-1][j];
                    if(j>0) left=dp[i][j-1];
                    dp[i][j] = (up + left) % mod;
                }
            }
        }
        return dp[n-1][m-1];
    }
};