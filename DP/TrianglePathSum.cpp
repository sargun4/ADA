#include <bits/stdc++.h>
using namespace std; 
// //memoi
// class Solution {
// public:
//     int solve(int n,int i,int j, vector<vector<int>>& triangle,vector<vector<int>>&dp){
//         if(i==n-1) return triangle[n-1][j];
//         if(dp[i][j]!=-1){
//             return dp[i][j];
//         }
//         int down=triangle[i][j]+solve(n,i+1,j,triangle,dp);
//         int rightdown=triangle[i][j]+solve(n,i+1,j+1,triangle,dp);
//         return dp[i][j]=min(down,rightdown);
//     }
//     int minimizeSum(int n, vector<vector<int>>& triangle){
//         vector<vector<int>>dp(n,vector<int>(n,-1));
//         return solve(n,0,0,triangle,dp);
//     }
// };
 
 //tab
//  T-O(N*N)-S
class Solution {
public:
    int minimizeSum(int n, vector<vector<int>>& triangle){
        int dp[n][n];
        for(int j=0;j<n;j++){
            dp[n-1][j]=triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int down=triangle[i][j]+dp[i+1][j];
                int rightdown=triangle[i][j]+dp[i+1][j+1];
                dp[i][j]=min(down,rightdown);
            }
        }
        return dp[0][0];
    }
};
 