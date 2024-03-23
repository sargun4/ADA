#include <bits/stdc++.h>
using namespace std; 
//tab
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>>dp(n+2,vector<int>(n+2,0));
        for(int i=n;i>=1;i--){
            for(int j=1;j<=n;j++){
                if(i>j) continue;
                int maxi=INT_MIN;
                for(int idx=i;idx<=j;idx++){
                    int cost=nums[i-1]*nums[idx]*nums[j+1]+dp[i][idx-1]+dp[idx+1][j];
                    maxi=max(maxi,cost);
                } 
                dp[i][j]=maxi; 
            }
        }
        return dp[1][n];
    }
};

//memo
// class Solution {
// public:
//     int f(int i,int j,vector<int> &nums,vector<vector<int>>&dp){
//         if(i>j) return 0;
//         int maxi=INT_MIN;
//         if(dp[i][j]!=-1) return dp[i][j];
//         for(int idx=i;idx<=j;idx++){
//             int cost=nums[i-1]*nums[idx]*nums[j+1]+f(i,idx-1,nums,dp)+f(idx+1,j,nums,dp);
//             maxi=max(maxi,cost);
//         } 
//         return dp[i][j]=maxi;

//     }
//     int maxCoins(vector<int>& nums) {
//         int n=nums.size();
//         nums.push_back(1);
//         nums.insert(nums.begin(),1);
//         vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
//         return f(1,n,nums,dp);
//     }
// };