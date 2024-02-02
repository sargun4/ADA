
#include <bits/stdc++.h>
using namespace std;

//memo
class Solution{
public:
    int solve(int price[],int i,int n,vector<vector<int>>&dp){
        if(i==0){
            return n*price[0];
        }
        if(dp[i][n]!=-1){
            return dp[i][n];  //return the result from memoization table
        }
        int notcut=solve(price,i-1,n,dp);
        int cut=INT_MIN;
        int rodlen=i+1;
        if(rodlen<=n){
            cut=price[i]+solve(price,i,n-rodlen,dp);
        }
        return dp[i][n]=max(notcut,cut);
    }
    int cutRod(int price[], int n) {
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(price,n-1,n,dp);
    }
};

// //Time Complexity: O(N^2)
// //Auxiliary Space: O(N)
// //tle-onrmal recursion
// class Solution{
// public:
//     int solve(int price[],int i,int n){
//         if(i==0){
//             return n*price[0];
//         }
//         //If we don't cut the rod of length i then total value will be n*
//         //price[i] because we can sell it at full price.
//         int notcut=solve(price,i-1,n);
//         int cut=INT_MIN;
//         int rodlen=i+1;
//         if(rodlen<=n){
//             cut=price[i]+solve(price,i,n-rodlen);
//         }
//         return max(notcut,cut);
//     }
//     int cutRod(int price[], int n) {
//         /* price[] is an array that contains prices of different lengths */
//         return solve(price,n-1,n);
//     }
// };