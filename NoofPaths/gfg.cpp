#include <bits/stdc++.h>
using namespace std;
// Time Complexity: O(M * N)
// Auxiliary Space: O(M * N) – 2D dp array of size M x N
class Solution {
public:
    long long int solve(int M, int N, vector<vector<long long int>> &dp) {
        if (M == 1 || N == 1)
            return dp[M][N] = 1; 
        // Check if the result is already computed
        if (dp[M][N] == 0) {
            dp[M][N] = solve(M - 1, N, dp) + solve(M, N - 1, dp);
        }
        return dp[M][N];
    } 
    long long int numberOfPaths(int M, int N) {
        // Initialize dp with zeros
        vector<vector<long long int>> dp(M + 1, vector<long long int>(N + 1, 0));
        return solve(M, N, dp);
    }
};
