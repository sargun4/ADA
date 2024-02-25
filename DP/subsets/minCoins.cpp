// https://www.geeksforgeeks.org/problems/number-of-coins1824/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

#include <bits/stdc++.h>
using namespace std;
class Solution{
	public:
	int minCoins(vector<int> &coins, int M, int V) { 
        vector<vector<int>> dp(M,vector<int>(V+1,0));
        for(int sum=0;sum<=V;sum++){
            if(sum%coins[0]==0){
                dp[0][sum]=sum/coins[0];
            }else{
                dp[0][sum]=1e9;
            }
        }
        for(int i=1;i<M;i++){
            for(int j=0;j<=V;j++){
                int nottake=0+dp[i-1][j];
                int take=INT_MAX;//since we nned min coins
                if(coins[i]<=j){
                    take=1+dp[i][j-coins[i]];
                }
                dp[i][j]=min(take,nottake);
            }
        }
        int ans=dp[M-1][V];
        if(ans>=1e9) return -1;
        return ans;
	} 
};
// #include <bits/stdc++.h>
// using namespace std;
// class Solution{
// 	public:
//     int solve(int i,int sum,vector<int> &coins,vector<vector<int>> &dp){
//         if(i==0){//only 1 elmnt,check the denomination
//             if(sum%coins[i]==0){
//                 return sum/coins[i];
//             }else{
//                 return 1e9;
//             }
//         }
//         if(dp[i][sum]!=-1){
//             return dp[i][sum];
//         }
//         int nottake=0+solve(i-1,sum,coins,dp);
//         int take=INT_MAX;//since we nned min coins
//         if(coins[i]<=sum){
//             take=1+solve(i,sum-coins[i],coins,dp);
//         }
//         return dp[i][sum]=min(take,nottake);
//     }
// 	int minCoins(vector<int> &coins, int M, int V) { 
//         vector<vector<int>> dp(M,vector<int>(V+1,-1));
//         int ans=solve(M-1,V,coins,dp);
//         if(ans>=1e9) return -1;
//         return ans;
// 	} 
// };