 
#include<bits/stdc++.h>
using namespace std; 
struct cell{  //make a cell structure
  int x;
  int y;
  int dist;
  
  cell(int x, int y, int dist){
      this->x=x;
      this->y=y;
      this->dist=dist;
  }
};

bool operator<(const cell& a, const cell& b){  //overloading constructor to choose bigger distance and push in heap so smaller dist can be on top
    return a.dist>=b.dist;
} 
class Solution{
    public:
    
    bool isSafe(int n, int x, int y){ 
        return x>=0 && x<n && y>=0 && y<n;
    }
    
    int minimumCostPath(vector<vector<int>>& grid)  {
        
        int n=grid.size(); 
        vector<vector<int>> dis(n+1, vector<int>(n+1,     	INT_MAX));
        
        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};
        
        priority_queue<cell> pq; //HEAP INITIALIZED
        
        dis[0][0]=grid[0][0];
        pq.push(cell(0,0,grid[0][0]));
        
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int x=curr.x;
            int y=curr.y;
            
            for(int i=0;i<4;i++){
                int newX=x+dx[i];
                int newY=y+dy[i];
                
                if(isSafe(n,newX,newY)==false){
                    continue;
                }
                
                if(dis[newX][newY]>dis[x][y]+grid[newX][newY]){ //IF NEW DISTANCE IS BIGGER THAN BEFORE, UPDATE WITH SMALLER ONE
                    dis[newX][newY]=dis[x][y]+grid[newX][newY];
                    pq.push(cell(newX,newY,dis[newX][newY]));
                }
            }
        }
        
        return dis[n-1][n-1];// RETURN DISTANCE
    }
};
// bool isvalid(int i, int j, int row, int col){
//     if(i<0 || j<0 || i>=row || j>=col)return false;
//     return true;
// }
//    int minimumCostPath(vector<vector<int>>& grid) 
//    {
//        // Code here
//        int row = grid.size(), col = grid[0].size(), 		    fcost =0;
//        vector<vector<int>> dist(row, vector<int>(col, INT_MAX));
//        dist[0][0] = grid[0][0];
//        priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
//        int dx[4] = {1,-1,0,0};
//        int dy[4] = {0,0,1,-1};
//        pq.push({dist[0][0],{0,0}});
//        while(!pq.empty()){
//            auto p = pq.top();
//            pq.pop();
//            int cost = p.first;
//            auto q = p.second;
//            int i = q.first;
//            int j = q.second;
//            fcost += cost;
//            if(i==row-1 && j==col-1) break;
//            for(int k =0; k<4; ++k){
//                int xdx = i + dx[k];
//                int ydy = j + dy[k];
//                if(isvalid(xdx, ydy, row, col)){
//                    if(dist[xdx][ydy]>=dist[i][j]+grid[xdx][ydy]){
//                        dist[xdx][ydy] = dist[i][j] + grid[xdx][ydy];
//                        pq.push({dist[xdx][ydy],{xdx, ydy}});
//                    }
//                }
//            }
//        }
//        return dist[row-1][col-1];
//    }
// //dp fails
// // class Solution {
// // public:
// //     int solve(int n, int i, int j, vector<vector<int>>& grid,vector<vector<int>>&dp) {
// //         if (i < 0 || j < 0 || i >= n || j >= n) {
// //             return INT_MAX;  // Return a large value for out of bounds
// //         }

// //         if (i == n - 1 && j == n - 1) {
// //             return grid[i][j];
// //         }
// //         if (dp[i][j] != -1){
// //             return dp[i][j];
// //         }
// //         int left = grid[i][j] + solve(n, i, j - 1, grid,dp);
// //         int right = grid[i][j] + solve(n, i, j + 1, grid,dp);
// //         int up = grid[i][j] + solve(n, i - 1, j, grid,dp);
// //         int down = grid[i][j] + solve(n, i + 1, j, grid,dp);

// //         int ans = min(left, min(right, min(up, down)));
// //         return dp[i][j]=ans;
// //     }

// //     int minimumCostPath(vector<vector<int>>& grid) {
// //         int n = grid.size();
// //         vector<vector<int>> dp(n,vector<int>(n,-1));
// //         return solve(n, 0, 0, grid,dp);
// //     }
// // };
 