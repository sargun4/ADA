#include <bits/stdc++.h>
using namespace std;
// //memo
// class Solution {
// public:
//     int solve(vector<int>& height, int i,vector<int> &dp){
//         if(i==0) return 0;
//         if(dp[i]!=-1){
//             return dp[i];
//         }
//         int l= solve(height,i-1,dp)+abs(height[i]-height[i-1]);
//         int r = INT_MAX;
//         if(i>1)
//             r=solve(height,i-2,dp)+abs(height[i]-height[i-2]); 
//         return dp[i]=min(l,r);
//     }
//     int minimumEnergy(vector<int>& height, int n) {
//         vector<int> dp(n+1,-1);
//         return solve(height,n-1,dp);
//     }
// };
//tabulatin

class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
        vector<int> dp(n,0);
        dp[0]=0;
        for(int i=1;i<n;i++){
            int l=dp[i-1]+abs(height[i]-height[i-1]);
            int r=INT_MAX;
            if(i>1){
                r=dp[i-2]+abs(height[i]-height[i-2]);
            }
            dp[i]=min(l,r);
        }
        return dp[n-1];
    }
};