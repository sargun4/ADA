#include <vector>
using namespace std; 
class Solution {
public:
    int solve(int i, int j, int sum, int k, int n, vector<vector<int>>& arr, vector<vector<vector<int>>>& dp) {
        // Check if out of bounds or if the sum becomes greater than k
        if (i >= n || j >= n || sum > k) {
            return 0;
        } 
        //if we have already calc the res for the current state,to avoid recomputing it again
        if (dp[i][j][sum] != -1) {
            return dp[i][j][sum];
        } 
        if (i == n - 1 && j == n - 1 && sum == k) {//we hv reached bottom-right cell &got required sum k
            return 1;
        } 
        // Recursive calls for moving down and right
        int down = solve(i + 1, j, sum + arr[i + 1][j], k, n, arr, dp);
        int right = solve(i, j + 1, sum + arr[i][j + 1], k, n, arr, dp);
        return dp[i][j][sum] = down + right;
    }

    int numberOfPath(int n, int k, vector<vector<int>>& arr) {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        return solve(0, 0, arr[0][0], k, n, arr, dp);
    }
};
