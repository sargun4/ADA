 
#include <bits/stdc++.h>
using namespace std;
 //tab  
class Solution{
public: 
    long long maximumProfit(vector<long long>&prices, int n, int fee) {
        vector<vector<long long>> dp(n+1,vector<long long>(2+1,0));
        for(int idx = n-1; idx >= 0; idx--) {
            for(int buy=0;buy<2;buy++){
                if(buy==1){
                    long long take=-prices[idx]-fee+dp[idx+1][0];
                    long long skip=0+dp[idx+1][1];
                    dp[idx][buy]=max(take,skip);
                }else{//sell
                    long long take=+prices[idx]+dp[idx+1][1];
                    long long skip=0+dp[idx+1][0];
                    dp[idx][buy]=max(take,skip);
                }
            }
        }
        return dp[0][1];
    }
}; 
//memeo
// class Solution{
// public:
//     int f(int idx,int buy,int fee,vector<long long>&prices,vector<vector<long long>>&dp){
//         int n = prices.size(); 
//         if(idx>=n) return 0;
//         if(buy==1){
//             long long take=-prices[idx]-fee+f(idx+1,0,fee,prices,dp);
//             long long skip=0+f(idx+1,1,fee,prices,dp);
//             dp[idx][buy]=max(take,skip);
//         }else{//sell
//             long long take=+prices[idx]+f(idx+1,1,fee,prices,dp);
//             long long skip=0+f(idx+1,0,fee,prices,dp);
//             dp[idx][buy]=max(take,skip);
//         }
//     }
//     long long maximumProfit(vector<long long>&prices, int n, int fee) {
//         vector<vector<long long>> dp(n,vector<long long>(2,-1));
//         return f(0,1,fee,prices,dp);
//     }
// }; 