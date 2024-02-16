#include <bits/stdc++.h>
using namespace std;
// A Naive recursive implementation of LCS problem
// Time Complexity: O(2m*n)
// Space: O(1)
int lcs(string X, string Y, int m, int n){
	if (m == 0 || n == 0)
		return 0;
	if (X[m - 1] == Y[n - 1])
		return 1 + lcs(X, Y, m - 1, n - 1);
	else
		return max(lcs(X, Y, m, n - 1),
				lcs(X, Y, m - 1, n));
}
// 1. Optimal Substructure
// 2. Overlapping Subproblems

// --------------dp Solution-------------------
// Top-Down DP
// Time Complexity: O(m * n) where m and n are the string lengths.
// Auxiliary Space: O(m * n) Here the recursive stack space is ignored.
 
int lcs(char* X, char* Y, int m, int n,
		vector<vector<int> >& dp){
	if (m == 0 || n == 0)
		return 0;
	if (X[m - 1] == Y[n - 1])
		return dp[m][n] = 1 + lcs(X, Y, m - 1, n - 1, dp);

	if (dp[m][n] != -1) {
		return dp[m][n];
	}
	return dp[m][n] = max(lcs(X, Y, m, n - 1, dp),
						lcs(X, Y, m - 1, n, dp));
}

//Longest Common Subsequence (LCS) using Bottom-Up (Tabulation):
 
// Create a 2D array dp[][] with rows and columns equal to the length of each input string plus 1 
// [the number of rows indicates the indices of S1 and the columns indicate the indices of S2].
// Initialize the first row and column of the dp array to 0.
// Iterate through the rows of the dp array, starting from 1 (say using iterator i).
// For each i, iterate all the columns from j = 1 to n:
// If S1[i-1] is equal to S2[j-1], set the current element of the dp array to the value of 
// the element to (dp[i-1][j-1] + 1).
// Else, set the current element of the dp array to the maximum value of dp[i-1][j] and dp[i][j-1].
// After the nested loops, the last element of the dp array will contain the length of the LCS.
 
// Time Complexity: O(m * n)
// Auxiliary Space: O(m * n)
 
int lcs(string X, string Y, int m, int n){
	// Initializing a matrix of size (m+1)*(n+1)
	int dp[m + 1][n + 1];
	// Build dp[m+1][n+1] in bottom up fashion.
	// dp[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1]
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0 || j == 0)
				dp[i][j] = 0;
			else if (X[i - 1] == Y[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	// dp[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1]
	return dp[m][n];
}
 