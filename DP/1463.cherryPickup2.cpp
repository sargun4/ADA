#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/cherry-pickup-ii/description/?envType=daily-question&envId=2024-02-11
//tab
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        // int dp[r][c1][c2]-max cherries collected by robot1 n robot2 till (r,c1) and (r,c2)
        // if(n==1) no of cols=1-> both robots on same cell->add only once
        
    }
};


// //memo
// // T-O(m*n*n*9)
// // S-O(m*n*n)-3d dp
// class Solution {
// public:
//     int m,n;
//     int dp[71][71][71];
//     int solve(vector<vector<int>>& grid,int r,int c1,int c2){
//         if(r>=m){//no cheries-since out of bounds
//             return 0;
//         }
//         if(dp[r][c1][c2]!=-1){
//             return dp[r][c1][c2];
//         }
//         int cherry=grid[r][c1];//same cell
//         if(c1!=c2){//not same- so add both
//             cherry+=grid[r][c2];
//         }
//         int ans=0;
//         for(int i=-1;i<=1;i++){ //for robot1
//             for(int j=-1;j<=1;j++){ //for robot2
//                 int newr=r+1;
//                 int newc1=c1+i;
//                 int newc2=c2+j;
//                 if(newc1>=0 && newc1<n && newc2>=0 && newc2<n)//safe cols
//                     ans=max(ans,solve(grid,newr,newc1,newc2));
//             }
//         }
//         return dp[r][c1][c2]=cherry+ans;
//     }
//     int cherryPickup(vector<vector<int>>& grid){
//         m=grid.size(); //no of rows
//         n=grid[0].size();//cols
//         memset(dp,-1,sizeof(dp));
//         return solve(grid,0,0,n-1);
//     }
// };