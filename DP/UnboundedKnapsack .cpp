
// Unbounded Knapsack 
// https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
 

#include <bits/stdc++.h>
using namespace std;
 
 //space opt
class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[]){
        // vector<vector<int>> dp(N,vector<int> (W+1,0));
        vector<int> prev(W+1,0);
        vector<int> curr(W+1,0);
        for(int w=0;w<=W;w++){
            prev[w]=val[0]*((int)(w/wt[0])); 
        }
        for(int i=1;i<N;i++){
            for(int w=0;w<=W;w++){
                int skip=0+prev[w];
                int take=INT_MIN;
                if(wt[i]<=w){
                    take=val[i]+curr[w-wt[i]];
                }
                curr[w]=max(take,skip);
            }
            prev=curr;
        }
        return prev[W];
    }
}; 

//  //tab
// class Solution{
// public:
//     int knapSack(int N, int W, int val[], int wt[]){
//         vector<vector<int>> dp(N,vector<int> (W+1,0));
//         for(int w=0;w<=W;w++){
//             dp[0][w]=val[0]*((int)(w/wt[0])); 
//         }
//         for(int i=1;i<N;i++){
//             for(int w=0;w<=W;w++){
//                 int skip=0+dp[i-1][w];
//                 int take=INT_MIN;
//                 if(wt[i]<=w){
//                     take=val[i]+dp[i][w-wt[i]];
//                 }
//                 dp[i][w]=max(take,skip);
//             }
//         }
//         return dp[N-1][W];
//     }
// }; 

//memo 
// class Solution{
// public:
//     int solve(int i,int W,int val[],int wt[],vector<vector<int>> &dp){
//         if(i==0){ //only1 item
//             return val[0]*((int)(W/wt[0])); 
//         }
//         if(dp[i][W]!=-1){
//             return dp[i][W];
//         }
//         int skip=0+solve(i-1,W,val,wt,dp);
//         int take=INT_MIN;
//         if(wt[i]<=W){
//             take=val[i]+solve(i,W-wt[i],val,wt,dp);
//         }
//         return dp[i][W]=max(take,skip);
//     }
//     int knapSack(int N, int W, int val[], int wt[]){
//         vector<vector<int>> dp(N,vector<int> (W+1,-1));
//         return solve(N-1,W,val,wt,dp);
//     }
// }; 