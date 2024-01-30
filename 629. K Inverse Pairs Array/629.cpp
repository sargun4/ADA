#include <bits/stdc++.h>
using namespace std; 
// // T-O(n*k*n-1)
// //memo
// class Solution {
// public:
//     int MOD=1e9+7;
//     int dp[1001][1001];
//     int solve(int n,int k){
//         // Base case
//         if(n == 0)return 0; //no elmnts
//         if(k==0) return 1; //sorted arr-no inversions
//         if(dp[n][k]!=-1){
//             return dp[n][k];
//         }
//         int res=0;
//         //for an arr of n len, at max only (n-1) inversins possible
//         for(int inv=0;inv<min(k,n-1);inv++){
//             res=(res%MOD+solve(n-1,k-inv)%MOD)%MOD;
//         }
//         return dp[n][k]=res;

//     }
//     int kInversePairs(int n, int k) {
//         memset(dp,-1,sizeof dp);//initializing dp array with -1
//         return solve(n,k);
//     }
// };

// T-O(n*k*n-1)
//S-O(n*k)-2d mat
//tabulation-bottom up
class Solution {
public:
    int MOD=1e9+7;
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n+1,vector<int>(k+1));
        // dp[i][j]=total no of arrs hving (1 to i)elmnts
        // and exactly j inversions
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=k;j++){
                for(int inv=0;inv<=min(i-1,j);inv++){
                    dp[i][j]=(dp[i][j]%MOD+dp[i-1][j-inv]%MOD)%MOD;
                }
            }
        }
        return dp[n][k];
    }
};