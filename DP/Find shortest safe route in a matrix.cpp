 
#include <bits/stdc++.h>
using namespace std;
 
class Solution{
public:
    int n,m;
    bool check(int i,int j,vector<vector<int>> &mat){
        if(i-1>=0 && mat[i-1][j]==0) return false;
        if(j-1>=0 && mat[i][j-1]==0) return false;

        if(i+1<n && mat[i+1][j]==0) return false;
        if(j+1<m && mat[i][j+1]==0) return false;
        
        return true;
    }
    int solve(int i,int j,vector<vector<int>> &mat,vector<vector<int>> &vis){
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j]==1 || mat[i][j]==0) return INT_MAX; 
        if(!check(i,j,mat))return INT_MAX; 
        if(j==0) return mat[i][0];
        vis[i][j] = 1;
        
        int left=solve(i,j-1,mat,vis);
        int up=solve(i-1,j,mat,vis);
        int down=solve(i+1,j,mat,vis);
        if(left!=INT_MAX) left+=mat[i][j];
        if(up!=INT_MAX) up+=mat[i][j];
        if(down!=INT_MAX) down+=mat[i][j];
        vis[i][j] = 0;
        return min(down,min(left,up));
        
    }
    int findShortestPath(vector<vector<int>> &mat){
       int n=mat.size();
       int m=mat[0].size();
       vector<vector<int>>vis(n,vector<int>(m,0));
       int mini=INT_MAX;
       for(int i=0;i<n;i++){
            mini=min(mini,solve(i,m-1,mat,vis));
       }
       if(mini==INT_MAX){
            return -1;
       }else{
        return mini;
       }
    }
};
 