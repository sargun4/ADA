// lc 221-https://leetcode.com/problems/maximal-square/description/


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        // Convert char matrix to int matrix
        vector<vector<int>> intmat(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                intmat[i][j] = matrix[i][j] - '0'; // Convert char to int
            }
        }

        // Base cases
        if (n == 0 || m == 0) return 0;
        if (n == 1 || m == 1) {
            // If any cell contains 1 we can form a 1x1 square with it
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (intmat[i][j] == 1)
                        return 1;
                }
            }
            return 0; // Else we won't be able to
        }

        int ans = 0; // Area of max square of 1s
        vector<vector<int>> dp = intmat; // Copy it

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1) { // Bottom-left cell
                    dp[i][j] = dp[i][j];
                    ans = max(ans, dp[i][j]);
                } else if (i == m - 1) { // Last row
                    dp[i][j] = dp[i][j];
                    ans = max(ans, dp[i][j]);
                } else if (j == n - 1) { // Last col
                    dp[i][j] = dp[i][j];
                    ans = max(ans, dp[i][j]);
                } else {
                    if (dp[i][j] == 0) {
                        dp[i][j] = 0;
                    } else { // If 1
                        int right = dp[i][j + 1];
                        int rd = dp[i + 1][j + 1];
                        int down = dp[i + 1][j];
                        dp[i][j] = min(right, min(down, rd)) + 1;
                        ans = max(ans, dp[i][j]);
                    }
                }
            }
        }
        return ans * ans;
    }
};
