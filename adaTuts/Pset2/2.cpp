// 2. Suppose you are managing the construction of billboards on the Stephen Daedalus Memorial
// Highway, a heavily travelled stretch of road that runs west-east for M miles. The possible

// sites for billboards are given by numbers x1, . . . , xn each in the interval [0, M]. More specifically, xi specifies the position of the i-th site along this highway. If you place a billboard at
// location xi, you receive a revenue of ri > 0.

// Regulations required by the countries highway department enforces that no two of the bill-
// boards can be within less than or equal to 5 miles of each other. You would like to place

// billboards at a subset of the sites so as to maximize your total revenue. Design an algorithm

// that takes the input instance of this problem as input and returns the maximum total rev-
// enue that can be obtained from any valid subset of sites. The running time of the algorithm

// should be polynomial in n.

#include <bits/stdc++.h>
using namespace std;
 
// Problem 2: Maximizing Billboard Revenue
// Given a stretch of road of length M, potential billboard sites, and associated revenues for each site, find the maximum total revenue while adhering to the constraint that no two billboards can be within 5 miles of each other.
// Recursive Solution (REC):
 
int recursiveMaxRevenue(const vector<int>& boards, const vector<int>& revenue, int i) {
    if (i < 0) {
        return 0;
    }
   // Option 1: Exclude the current site
    int excludeCurrent = recursiveMaxRevenue(boards, revenue, i - 1);

    // Option 2: Include the current site and skip the previous site within 5 miles
    int includeCurrent = revenue[i];
    for (int j = i - 1; j >= 0; --j) {
        if (boards[i] - boards[j] > 5) {
            includeCurrent += recursiveMaxRevenue(boards, revenue, j);
            break;
        }
    }

    return max(excludeCurrent, includeCurrent);
}
// Time Complexity (TC): Exponential, O(2^n)
// Space Complexity (SC): O(n) for the recursive call stack


// Memoized Solution (MEMO): 
int memoizedMaxRevenue(const vector<int>& boards, const vector<int>& revenue, int i, unordered_map<int, int>& dp) {
    if (i < 0) {
        return 0;
    }

    if (dp.find(i) != dp.end()) {
        return dp[i];
    }

    // Option 1: Exclude the current site
    int excludeCurrent = memoizedMaxRevenue(boards, revenue, i - 1, dp);

    // Option 2: Include the current site and skip the previous site within 5 miles
    int includeCurrent = revenue[i];
    for (int j = i - 1; j >= 0; --j) {
        if (boards[i] - boards[j] > 5) {
            includeCurrent += memoizedMaxRevenue(boards, revenue, j, dp);
            break;
        }
    }

    dp[i] = max(excludeCurrent, includeCurrent);
    return dp[i];
}
// Time Complexity (TC): O(n^2) (due to memoization)
// Space Complexity (SC): O(n) for the memoization table and O(n) for the recursive call stack


// Tabulation Solution (TAB): 
int maxRevenue(const vector<int>& boards, const vector<int>& revenue) {
    int n = boards.size();
    vector<int> dp(n + 1, 0); // dp[i] stores the maximum revenue up to the i-th site

    for (int i = 1; i <= n; ++i) {
        int excludeCurrent = dp[i - 1];

        int includeCurrent = revenue[i - 1];
        for (int j = i - 2; j >= 0; --j) {
            if (boards[i - 1] - boards[j] > 5) {
                includeCurrent += dp[j];
                break;
            }
        }

        dp[i] = max(excludeCurrent, includeCurrent);
    }

    return dp[n];
}
// Time Complexity (TC): O(n^2)
// Space Complexity (SC): O(n) for the dp array