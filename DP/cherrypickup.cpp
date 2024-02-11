#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/cherry-pickup/
 
class Solution {
public:
    int solve(int n, int r1, int c1, int r2, int c2, vector<vector<int>>& grid, unordered_map<string, int>& dp) {
        //base case- out of bounds or -1
        if (r1 >= n || c1 >= n || r2 >= n || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1) {
            return -1e9;
        }

        //base case- both players reach the destination
        if (r1 == n - 1 && c1 == n - 1) {
            return grid[r1][c1];
        }
        //if the subproblem is already solved
        string key = to_string(r1) + "_" + to_string(c1) + "_" + to_string(r2) + "_" + to_string(c2);
        if (dp.find(key) != dp.end()) {
            return dp[key];
        }

        int cherries = 0;
        if (r1 == r2 && c1 == c2) {//both ppl meet at same cell- so take chery only once
            cherries += grid[r1][c1];
        } else {
            cherries += grid[r1][c1] + grid[r2][c2];
        }

        //recursive call for right,down for both ppl
        int rr = solve(n, r1, c1 + 1, r2, c2 + 1, grid, dp);
        int dd = solve(n, r1 + 1, c1, r2 + 1, c2, grid, dp);
        int rd = solve(n, r1, c1 + 1, r2 + 1, c2, grid, dp);
        int dr = solve(n, r1 + 1, c1, r2, c2 + 1, grid, dp);

        // Calculate the maximum cherries and store in dp
        cherries += max(max(rr, dd), max(rd, dr));
        dp[key] = cherries;

        return cherries;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<string, int> dp;
        return max(0, solve(n, 0, 0, 0, 0, grid, dp));
    }
};


class Solution {
public:
    int solve(int n,int r1,int c1,int r2,int c2,vector<vector<int>>& grid){ //consider 2 ppl going from (0,0) to (n-1,n-1)-covers going feom (n-1,n-1) to 0,0 case also.
       //base-out of bounds or -1
       if(r1>n||r2>n||c1>n||c2>n||grid[r1][c1]==-1||grid[r2][c2]==-1){
            return -1e9;
       }
       //base-when both ppl reach dest
       if(r1==n-1&&c1==n-1)
            return grid[r1][c1];

       int cherries=0;
       if(r1==r2 && c1==c2){//both ppl meet at same cell- so take chery only once
            cherries+=grid[r1][c1];
       }else{
            cherries+=grid[r1][c1]+grid[r2][c2];
       }
       //recursive call for right,down for both ppl
       int rr=solve(n,r1,c1+1,r2,c2+1,grid);
       int dd=solve(n,r1+1,c1,r2+1,c2,grid);
       int rd=solve(n,r1,c1+1,r2+1,c2,grid);
       int dr=solve(n,r1+1,c1,r2,c2+1,grid);
       //return the maximum of all possible paths

       cherries+=max(max(rr,dd),max(rd,dr));
       return cherries;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        return solve(n,0,0,0,0,grid);
    }
};