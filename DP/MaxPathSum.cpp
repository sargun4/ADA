 
// #include <bits/stdc++.h>
// using namespace std;
// // 1. Recursive Approach: [O(N*3^(N*N)) & O(N+N)  (TLE ❌)

// class Solution{
// public:
//     int helper(int i, int j, int N, vector<vector<int>> Matrix){
//         if(j < 0 || j >= N) return -1e9;
//         if(i == 0) return Matrix[0][j];
        
//         int up = Matrix[i][j] + helper(i-1, j, N, Matrix);
//         int ld = Matrix[i][j] + helper(i-1, j-1, N, Matrix);
//         int rd = Matrix[i][j] + helper(i-1, j+1, N, Matrix);
        
//         return max(up, max(ld, rd));
//     }

//     int maximumPath(int N, vector<vector<int>> Matrix){
//         int maxi = INT_MIN;
        
//         for(int j=0;j<N;j++){
//             int ans = helper(N-1, j, N, Matrix);
//             maxi = max(maxi, ans);
//         }
//         return maxi;
//     }
// };
 

// // 2. DP - Memoization: [O(N*N) & O(N*N) + O(N)]

// class Solution{
// public:
//     int helper(int i, int j, int N, vector<vector<int>> &Matrix, vector<vector<int>> &dp){
//         if(j < 0 || j >= N) return -1e9;
//         if(i == 0) return Matrix[0][j];
        
//         if(dp[i][j] != -1) return dp[i][j];
        
//         int up = Matrix[i][j] + helper(i-1, j, N, Matrix, dp);
//         int ld = Matrix[i][j] + helper(i-1, j-1, N, Matrix, dp);
//         int rd = Matrix[i][j] + helper(i-1, j+1, N, Matrix, dp);
        
//         return dp[i][j] = max(up, max(ld, rd));
//     }

//     int maximumPath(int N, vector<vector<int>> Matrix){
//         vector<vector<int>> dp(N, vector<int> (N, -1));
        
//         int maxi = INT_MIN;
        
//         for(int j=0;j<N;j++){
//             int ans = helper(N-1, j, N, Matrix, dp);
//             maxi = max(maxi, ans);
//         }
//         return maxi;
//     }
// };
 

// // 3. DP - Tabulation: [O(N*N) + O(N) & O(N*N)]

// class Solution{
// public:
//     int maximumPath(int N, vector<vector<int>> Matrix){
//         vector<vector<int>> dp(N, vector<int> (N, 0));
        
//         for(int j=0;j<N;j++) dp[0][j] = Matrix[0][j];
        
//         for(int i=1;i<N;i++){
//             for(int j=0;j<N;j++){
//                 int up = Matrix[i][j] + dp[i-1][j];
                
//                 int ld = Matrix[i][j];
//                 (j >= 0)? ld += dp[i-1][j-1] : ld += -1e9;
                
//                 int rd = Matrix[i][j];
//                 (j+1 < N)? rd += dp[i-1][j+1] : rd += -1e9;
                
//                 dp[i][j] = max(up, max(ld, rd));
//             }
//         }
        
//         int maxi = INT_MIN;
        
//         for(int j=0;j<N;j++){
//             maxi = max(maxi, dp[N-1][j]);
//         }
//         return maxi;
//     }
// };
 

// // 4. Optimized - Iterative: [O(N*N) + O(N) & O(N)]

// class Solution{
// public:
//     int maximumPath(int N, vector<vector<int>> Matrix){
//         vector<int> prev(N, 0);
        
//         for(int j=0;j<N;j++) prev[j] = Matrix[0][j];
        
//         for(int i=1;i<N;i++){
//             vector<int> cur(N, 0);
//             for(int j=0;j<N;j++){
//                 int up = Matrix[i][j] + prev[j];
                
//                 int ld = Matrix[i][j];
//                 (j >= 0)? ld += prev[j-1] : ld += -1e9;
                
//                 int rd = Matrix[i][j];
//                 (j+1 < N)? rd += prev[j+1] : rd += -1e9;
                
//                 cur[j] = max(up, max(ld, rd));
//             }
//             prev = cur;
//         }
        
//         int maxi = INT_MIN;
        
//         for(int j=0;j<N;j++){
//             maxi = max(maxi, prev[j]);
//         }
//         return maxi;
//     }
// };