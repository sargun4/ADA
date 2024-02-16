
#include <bits/stdc++.h>
using namespace std;
//tab
class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M){
        vector<vector<int>> dp(n,vector<int>(m,0));

        for(int j = m-1; j >= 0; j--) {
            for(int i = 0; i < n; i++) {
                if(j == m-1) {
                    dp[i][j] = M[i][j];
                } else {
                    int right = dp[i][j+1];
                    int rightup = (i > 0) ? dp[i-1][j+1] : 0;
                    int rightdown = (i < n-1) ? dp[i+1][j+1] : 0;

                    if(i == n-1) { // last row - can only go right or right up, select whichever is max
                        dp[i][j] = M[i][j] + max(right, rightup);
                    } else if(i == 0) { // first row - can only go right or right down, select whichever is max
                        dp[i][j] = M[i][j] + max(right, rightdown);
                    } else { // if somewhere in the middle, 3 choices
                        dp[i][j] = M[i][j] + max(rightdown, max(right, rightup));
                    }
                }
            }
        }

        int ans = INT_MIN;
        for(int i = 0; i < n; i++) {
            ans = max(ans, dp[i][0]);
        }
        return ans;
    }
};

// //memo-tle
// class Solution{
// public:
//     int solve(int i,int j, vector<vector<int>>&M, vector<vector<int>>&dp){
//         int n=M.size();
//         int m=M[0].size();
//         if(j>m-1||i>n-1||i<0){
//             return 0;
//         }
//         //base
//         if(j==m-1){
//             return M[i][j]; 
//         }
        
//         int right=solve(i,j+1,M,dp);
//         int rightup=solve(i-1,j+1,M,dp);
//         int rightdown=solve(i+1,j+1,M,dp);

//         if(i==n-1){ //last row- can only go right or right up,select whichever is max
//             return dp[i][j]=M[i][j]+max(right,rightup);
//         }else if(i==0){//first row- can only go right or right down,select whicher is max
//             return dp[i][j]=M[i][j]+max(right,rightdown);
//         }else{//if smwhere in midle,3choicse
//             return dp[i][j]=M[i][j]+max(rightdown,max(right,rightup));
//         }
//     }
//     int maxGold(int n, int m, vector<vector<int>> M){
//         vector<vector<int>> dp(n,vector<int>(m,-1));
//         int ans=INT_MIN;
//         for(int i=0;i<n;i++){
//             ans=max(ans,solve(i,0,M,dp));
//         }
//         return ans;
//     }
// };