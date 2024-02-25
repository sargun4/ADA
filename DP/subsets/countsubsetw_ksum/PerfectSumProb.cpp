
#include <bits/stdc++.h>
using namespace std;
class Solution{
	public:
    int solve(int i,int sum,int arr[],vector<vector<int>> &dp){
        if(sum==0) return 1;
        if(i<0) return arr[0]==sum;
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        int nottake = solve(i - 1, sum, arr, dp);
        int take=0;
        if(arr[i]<=sum){
            take=solve(i-1,sum-arr[i],arr,dp);
        }
        return dp[i][sum]=nottake+take;
    }
	int perfectSum(int arr[], int n, int sum){
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
	    return solve(n-1,sum,arr,dp);
	}
};