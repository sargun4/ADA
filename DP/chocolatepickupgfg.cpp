// https://www.geeksforgeeks.org/problems/chocolates-pickup/1
#include <bits/stdc++.h>
using namespace std;
//tab
class Solution {
public:
    int solve(int n, int m, vector<vector<int>>& grid){
        //int dp[n][m][m];
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        for(int j1=0;j1<m;j1++){
            for(int j2=0;j2<m;j2++){
                if(j1==j2) dp[n-1][j1][j2]=grid[n-1][j1];
                else  dp[n-1][j1][j2]=grid[n-1][j1]+grid[n-1][j2];
            }
        }
        for(int i=n-2;i>=0;i--){
            for(int j1=0;j1<m;j1++){
                for(int j2=0;j2<m;j2++){
                    int maxi=-1e9;
                    for(int r=-1;r<=1;r++){
                        for(int c=-1;c<=1;c++){
                            int val=0;
                            if(j1==j2) val=grid[i][j1];
                            else val=grid[i][j1]+grid[i][j2];
                            if(j1+r>=0 && j1+r<m && j2+c>=0 && j2+c<m)
                                val+=dp[i+1][j1+r][j2+c];
                            else
                                val+=-1e9;
                            maxi=max(maxi,val);
                        }
                    }
                    dp[i][j1][j2]=maxi;
                }
            }
        }
        return dp[0][0][m-1];
    }
};

// class Solution {
// public:
//     int f(int n,int m,int i,int j1,int j2,vector<vector<int>>& grid,vector<vector<vector<int>>> &dp){
//         if(j1<0||j2<0||j1>=m||j2>=m){
//             return -1e8;
//         }
//         if(dp[i][j1][j2]!=-1){
//             return dp[i][j1][j2];
//         }
//         if(i==n-1){//reached last row
//             if(j1==j2){
//                 return grid[i][j1];
//             }else{
//                 return grid[i][j1]+grid[i][j2];
//             }
//         }
//         int maxi=-1e8;
//         for(int r=-1;r<=1;r++){
//             for(int c=-1;c<=1;c++){
//                 int val=0;
//                 if(j1==j2) val=grid[i][j1];
//                 else val=grid[i][j1]+grid[i][j2];
//                 val+=f(n,m,i+1,j1+r,j2+c,grid,dp);
//                 maxi=max(maxi,val);
//             }
//         }
//         return dp[i][j1][j2]=maxi;
//     }
//     int solve(int n, int m, vector<vector<int>>& grid){
//         //int dp[n][m][m];
//         vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
//         return f(n-1,m-1,0,0,0,grid,dp);
//     }
// };

// wrong
// class Solution {
// public:
//     int pickup(int n, int m, int r1, int c1, int r2, int c2, vector<vector<int>>& grid) {
//         // Base case - out of bounds check for both robots
//         if (c1 < 0|| c2<0 || c1 >= m || c2>=m) {
//             return -1e9;
//         }

//         // Base case - reached last row
//         if (r1 == n - 1 && r2 == n - 1) {
//             int maxi = 0;
//             for (int j = 0; j < m; j++) {
//                 maxi = max(maxi, grid[r1][j]);
//             }
//             return maxi;
//         }

//         // Base case - both robots in the same cell
//         int cherries = (r1 == r2 && c1 == c2) ? grid[r1][c1] : grid[r1][c1] + grid[r2][c2];

//         // Define possible movements
//         vector<pair<int, int>> moves = {{1, 1}, {1, 0}, {1, -1}};

//         // Recursive cases - iterate through all possible movements
//         int maxi = 0;  // Use 0 as the initial value
//         for (auto& move1 : moves) {
//             for (auto& move2 : moves) {
//                 int rr = pickup(n, m, r1 + move1.first, c1 + move1.second, r2 + move2.first, c2 + move2.second, grid);
//                 maxi = max(maxi, rr);
//             }
//         }

//         return cherries + maxi;  // Add cherries directly, as we initialized maxi to 0
//     }

//     int solve(int n, int m, vector<vector<int>>& grid) {
//         return max(0, pickup(n, m, 0, 0, 0, m - 1, grid));
//     }
// };

// class Solution {
// public:
//     int pickup(int n,int m,int r1,int c1,int r2,int c2, vector<vector<int>>& grid){
//         //base case-out of bounds check for both robots
//         if(r1>=n||r2>=n||c1>=m||c2>=m){
//             return -1e9;
//         }
//         // base case - reached last row
//         if (r1 == n - 1 && r2 == n - 1) {
//             int maxi = INT_MIN;
//             for (int j = 0; j < m; j++) {
//                 maxi = max(maxi, grid[r1][j]);
//             }
//             return maxi;
//         }

//         int cherries=0;
//         if(r1==r2 && c1==c2){
//             cherries+=grid[r1][c1];
//         }else{
//             cherries+=grid[r1][c1]+grid[r2][c2];
//         }
// //9 cases-
// // rr-both move (i+1,j+1)
// // rd-p1 moves (i+1,j+1) ,p2 moves (i+1,j)
// // rl-p1 moves (i+1,j+1), p2 moves (i+1,j-1)
// // dd-both move (i+1,j)
// // dr-p1 moves (i+1,j), p2 moves (i+1,j+1)
// // dd-p1 moves (i+1,j), p2 moves (i+1,j)
// // dl-p1 moves (i+1,j), p2 moves (i+1,j-1)
// // lr-p1 moves (i+1,j-1), p2 moves (i+1,j+1)
// // ld-p1 moves (i+1,j-1), p2 moves (i+1,j)
// // ll-p1 moves (i+1,j-1), p2 moves (i+1,j-1)
//         int rr=pickup(n,m,r1+1,c1+1,r2+1,c2+1,grid);
//         int rd=pickup(n,m,r1+1,c1+1,r2+1,c2,grid);
//         int rl=pickup(n,m,r1+1,c1+1,r2+1,c2-1,grid);
//         int dd=pickup(n,m,r1+1,c1,r2+1,c2,grid);
//         int dr=pickup(n,m,r1+1,c1,r2+1,c2+1,grid);
//         int dl=pickup(n,m,r1+1,c1,r1+1,c2-1,grid);
//         int lr=pickup(n,m,r1+1,c1-1,r2+1,c2+1,grid);
//         int ld=pickup(n,m,r1+1,c1-1,r2+1,c2,grid);
//         int ll=pickup(n,m,r1+1,c1-1,r2+1,c2-1,grid);

//         cherries += max({rr,rd,rl,dd,dr,dl,lr,ld,ll});
//         return cherries;
//     }
//     int solve(int n, int m, vector<vector<int>>& grid){ 
//         return max(0, pickup(n, m, 0, 0, 0, m - 1, grid));
//     }
// };