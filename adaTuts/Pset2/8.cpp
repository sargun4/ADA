#include <iostream>
#include <vector>

using namespace std;

// Function to count subsets of size k =nCk
int countSubsetsOfSizeK(const vector<int>& A, int n, int k, vector<vector<int>>& dp) {
    // Base cases
    if (k == 0 || k == n) {
        return 1;
    }
    // Check if the result is already memoized
    if (dp[n][k] != -1) {
        return dp[n][k];
    }
    // Recursively calculate the count
    int count = countSubsetsOfSizeK(A, n - 1, k - 1, dp) + countSubsetsOfSizeK(A, n - 1, k, dp);
    // Memoize the result
    dp[n][k] = count;

    return count;
}

// Function to initialize memoization table and call the recursive function
int countSubsetsOfSizeKWrapper(const vector<int>& A, int n, int k) {
    // Memoization table
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    // Call the recursive function
    return countSubsetsOfSizeK(A, n, k, dp);
}
 