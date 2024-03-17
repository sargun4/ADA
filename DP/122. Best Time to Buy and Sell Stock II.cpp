
#include <bits/stdc++.h>
using namespace std;
//tab
class Solution {
public: 
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        dp[n][0]=dp[n][1]=0;
        for(int idx=n-1; idx>=0; idx--){
            for(int buy=0; buy<=1; buy++){
                int profit=0;
                if(buy==1){//two options: either we buy the stock on the current day or we skip it.
                    int take=-prices[idx]+dp[idx+1][0]; //buy that stock and move to next=>now cant buy so buy=0
                    int skip=0+dp[idx+1][1];//skip that stock and move to next=>now hv liberty to buy so buy=1
                    profit=max(take,skip);
                }else if(buy==0){ //sell-e two options: either we sell the stock on the current day or we skip it.
                    int take=+prices[idx]+dp[idx+1][1]; //sell that stock and move to next=>now can buy so buy=1
                    int skip=0+dp[idx+1][0];//dont sell that stock and move to next=>now cant buy so buy=0
                    profit=max(take,skip);
                }
                dp[idx][buy]=profit;
            }
        }
        return dp[0][1];
    }
};
// //memo
// // t-O(n*2)
// class Solution {
// public:
//     int f(int idx,int buy,vector<int>&prices,vector<vector<int>> &dp){
//         int n=prices.size();
//         if(idx==n) return 0;//
//         if(dp[idx][buy]!=-1){
//             return dp[idx][buy];
//         }
//         int profit=0;
//         if(buy==1){
//             int take=-prices[idx]+f(idx+1,0,prices,dp); //buy that stock and move to next=>now cant buy so buy=0
//             int skip=0+f(idx+1,1,prices,dp);//skip that stock and move to next=>now hv liberty to buy so buy=1
//             profit=max(take,skip);
//         }else if(buy==0){//sell
//             int take=+prices[idx]+f(idx+1,1,prices,dp); //sell that stock and move to next=>now can buy so buy=1
//             int skip=0+f(idx+1,0,prices,dp);//dont sell that stock and move to next=>now cant buy so buy=0
//             profit=max(take,skip);
//         }
//         return dp[idx][buy]=profit;
//     }
//     int maxProfit(vector<int>& prices) {
//         int n=prices.size();
//         vector<vector<int>> dp(n,vector<int>(2,-1));
//         return f(0,1,prices,dp);
//     }
// };