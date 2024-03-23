 
#include<bits/stdc++.h>
using namespace std; 
// Time O(N) Space (O[N][N])
class Solution{
    public: 
    int solve(int idx, int previdx, int arr[],int n,vector<vector<int>> &dp){
       if(n == idx) return 0; 
       if(dp[idx][previdx+1]!=-1) return dp[idx][previdx+1];
       int len=0+solve(idx+1,previdx,arr,n,dp);
       if(previdx==-1||arr[idx]>arr[previdx]){
        len=max(len,1+solve(idx+1,previdx,arr,n,dp));
       }
    return dp[idx][previdx+1]=len;
   }
   int longestSubsequence(int n, int a[]){
      vector<vector<int>> dp(n+1, vector<int>(n+2, -1));
      return solve(0,-1,a,n,dp);
   }
};

 