// https://leetcode.com/problems/minimum-path-sum/
#include <bits/stdc++.h>
using namespace std;
// class Solution {
// public:
//     int solve(vector<vector<int>>& grid,int i,int j,int m,int n,vector<vector<int>>&dp){
//         if(i==m-1 && j==n-1){
//             return grid[i][j];
//         }
//         if(dp[i][j]!=-1){
//             return dp[i][j];
//         }
//         if(i==m-1){ //last row- can only go right
//             return dp[i][j]=grid[i][j]+solve(grid,i,j+1,m,n,dp);
//         }else if(j==n-1){//last col- can only go down
//             return dp[i][j]=grid[i][j]+solve(grid,i+1,j,m,n,dp);
//         }else{
//             return dp[i][j]=grid[i][j]+min(solve(grid,i,j+1,m,n,dp),solve(grid,i+1,j,m,n,dp));
//         }
//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();

//         vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
//         return solve(grid,0,0,m,n,dp);
//     }
// };
class Solution {
public:
  int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size(); 
        vector<vector<int>> dp(m,vector<int>(n));
        //dp[i][j]=min path sum to  reach(i,j) frm (0,0)
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(i==m-1 && j==n-1){//reached last cell
                    dp[i][j]=grid[i][j];
                }else if(i==m-1){//last row
                    dp[i][j]=dp[i][j+1]+grid[i][j];
                }else if(j==n-1){//last column
                    dp[i][j]=dp[i+1][j]+grid[i][j];
                }else{
                    dp[i][j]=min(dp[i][j+1],dp[i+1][j])+grid[i][j];
                }
            }
        }
        return dp[0][0];
    }
};


// class Solution {
// public:
//   int minPathSum(vector<vector<int>>& grid) {
//         int m=grid.size();
//         int n=grid[0].size();

//         vector<vector<int>> dp(m,vector<int>(n));
//         //dp[i][j]=min path sum to  reach(i,j) frm (0,0)
//         dp[0][0]=grid[0][0];
//         //fill 1st col
//         for(int i=1;i<m;i++){
//             dp[i][0]=dp[i-1][0]+grid[i][0];
//         }
//         //fill 1st row
//         for(int j=1;j<n;j++){
//             dp[0][j]=dp[0][j-1]+grid[0][j];
//         }
//         for(int i=1;i<m;i++){
//             for(int j=1;j<n;j++){
//                 dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j];
//             }
//         }
//         return dp[m-1][n-1];
//     }
// };