//tab
#include <bits/stdc++.h>
using namespace std;
class Solution{   
public:
 bool isSubsetSum(vector<int> arr, int sum) { 
        int n = arr.size(); 
        // Create a DP table
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false)); 
        for (int i = 0; i <= n; ++i)
            dp[i][0] = true; 
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= sum; ++j) {
                if (j < arr[i - 1]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
                }
            }
        } 
    return dp[n][sum];
 }
};
// //tle-memo
// class Solution{   
// public:
//     bool solve(int idx,int target,vector<int>&arr,vector<vector<int>> &dp){
//         //base cases
//         if(target==0) return true;// case when we dont take any elmnts to get sum=0=target->we can always get sum=0
//         if (idx ==0) return (arr[0]==target); //if we hv single elmtn compare target and elmnt
//         if(dp[idx][target]!=-1){
//             return dp[idx][target];
//         }
//         bool nottake=solve(idx-1,target,arr,dp);
//         bool take=false;
//         if(arr[idx]<=target){
//             take=solve(idx-1,target-arr[idx],arr,dp);
//         }
//         return take | nottake;
//     }
//     bool isSubsetSum(vector<int>arr, int sum){
//         int n=arr.size();
//         int k=sum;
//         vector<vector<int>> dp(n,vector<int>(k+1,-1));
//         return solve(n-1,k,arr,dp);
//     }
// };