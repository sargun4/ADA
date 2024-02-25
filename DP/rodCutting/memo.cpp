
#include <bits/stdc++.h>
using namespace std;
 
//spaceopt
class Solution{
public: 
    int cutRod(int price[], int n) {
        // vector<vector<int>> dp(n,vector<int>(n+1,0));
        vector<int> prev(n+1,0);
        vector<int> curr(n+1,0);
        for(int j=0;j<=n;j++){
            prev[j]=j*price[0];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=n;j++){
                int skip=0+prev[j];
                int take=INT_MIN;
                int rodlen=i+1;
                if(rodlen<=j){
                    take=price[i]+curr[j-rodlen];
                }
                curr[j]=max(take,skip);
            }
        }
        return prev[n];
    }
};
 
// //tab
// class Solution{
// public: 
//     int cutRod(int price[], int n) {
//         vector<vector<int>> dp(n,vector<int>(n+1,0));
//         for(int j=0;j<=n;j++){
//             dp[0][j]=j*price[0];
//         }
//         for(int i=1;i<n;i++){
//             for(int j=0;j<=n;j++){
//                 int skip=0+dp[i-1][j];
//                 int take=INT_MIN;
//                 int rodlen=i+1;
//                 if(rodlen<=j){
//                     take=price[i]+dp[i][j-rodlen];
//                 }
//                 dp[i][j]=max(take,skip);
//             }
//         }
//         return dp[n-1][n];
//     }
// };
// //memo
// class Solution{
// public:
//     int solve(int i,int n,int price[],vector<vector<int>> &dp){
//         if(i==0){
//             return n*price[0];
//         }
//         if(dp[i][n]!=-1){
//             return dp[i][n];
//         }
//         int skip=0+solve(i-1,n,price,dp);
//         int take=INT_MIN;
//         int rodlen=i+1;
//         if(rodlen<=n){
//             take=price[i]+solve(i,n-rodlen,price,dp);
//         }
//         return dp[i][n]= max(take,skip);
//     }
//     int cutRod(int price[], int n) {
//         vector<vector<int>> dp(n,vector<int>(n+1,-1));
//         return solve(n-1,n,price,dp);
//     }
// };

// // //Time Complexity: O(N^2)
// // //Auxiliary Space: O(N) 