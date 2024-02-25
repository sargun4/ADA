
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    long long int solve(int coins[],int i,int sum,vector<vector<long long int>> &dp){
        if(i==0){
            return sum%coins[i]==0;
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        long long int exclude=solve(coins,i-1,sum,dp);
        long long int include=0;
        if(sum>=coins[i]){
            include=solve(coins,i,sum-coins[i],dp);
        }
        
        
        return dp[i][sum]=exclude+include;
    }
    long long int count(int coins[], int N, int sum) {
        vector<vector<long long int>> dp(N,vector<long long int>(sum+1,-1));
        return solve(coins,N-1,sum,dp);
    }
};