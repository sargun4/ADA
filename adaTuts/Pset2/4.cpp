// 4. Suppose you are working on a lightweight consulting business, just you – two associates,
// and some rented equipment. Your clients are distributed between north part, and south
// part of the country. Each month, you can either run your business from an office in Delhi
// (DEL), or from an office in Mumbai (BOM). In the i-th month, you will incur an operating
// cost of di
// if you run from DEL; you will incur an operating cost of mi

// if you run from BOM.
// However, if you run the business in one city in the i-th month and move it to another city in
// the (i + 1)-th month, then you incur a fixed moving cost of M to switch base offices.
// Given a sequence of n months, a plan is a sequence of n locations – each one equal to either
// DEL or BOM – such that the i-th location indicates a city in which you will be based in the
// i-th month. The cost of a plan is the sum of the operating costs for each of the n months, plus
// a moving cost of M for each time you switch cities. The plan can begin in any of the two
// cities.
// Example: Suppose that n = 4, M = 10, and the operating costs are given by the following
// example. The values are d1 = 1, d2 = 3, d3 = 20, d4 = 30 and m1 = 50, m2 = 20, m3 = 2, m4 =
// 2.
//  The plan of a minimum cost would be the sequence of locations (DEL, DEL, BOM, BOM)
// with a total cost 1 + 3 + 10 + 2 + 4 while the term 10 stands for moving cost M that was
// conducted between the second and the third month.
// Design and analyze a polynomial-time algorithm that takes the values n, M, the values di’s
// and mi’s and returns the cost of an optimal plan.


// Problem 4: Minimize Operating and Moving Costs for Business Plan
// Given a consulting business with offices in Delhi (DEL) and Mumbai (BOM), along with operating costs for each month and fixed moving costs, find the cost of an optimal plan that minimizes the total expenses.


#include <bits/stdc++.h>
using namespace std;

// Recursive Solution (REC):
int recursiveMinCost(const vector<int>& d, const vector<int>& m, int i, int currentCity, int M) {
    if (i == 0) {
        return min(d[i], m[i]);
    }
    int switchCityCost = recursiveMinCost(d, m, i - 1, 1 - currentCity, M) + M;
    int stayInCurrentCityCost = min(d[i] + recursiveMinCost(d, m, i - 1, currentCity, M),
                                    m[i] + switchCityCost);

    return stayInCurrentCityCost;
}
// Time Complexity (TC): Exponential, O(2^n)
// Space Complexity (SC): O(n) for the recursive call stack


// Memoized Solution (MEMO):
int memoizedMinCost(const vector<int>& d, const vector<int>& m, int i, int currentCity, int M, unordered_map<string, int>& memo) {
    if (i == 0) {
        return min(d[i], m[i]);
    }

    string key = to_string(i) + "-" + to_string(currentCity);
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }

    int switchCityCost = memoizedMinCost(d, m, i - 1, 1 - currentCity, M, memo) + M;
    int stayInCurrentCityCost = min(d[i] + memoizedMinCost(d, m, i - 1, currentCity, M, memo),
                                    m[i] + switchCityCost);

    memo[key] = stayInCurrentCityCost;
    return stayInCurrentCityCost;
}
// Time Complexity (TC): O(n^2) (due to memoization)
// Space Complexity (SC): O(n) for the memoization table and O(n) for the recursive call stack


// Tabulation Solution (TAB):
int minCost(const vector<int>& d, const vector<int>& m, int M) {
    int n = d.size();
    vector<vector<int>> dp(n, vector<int>(2, 0)); // dp[i][j] stores the minimum cost up to the i-th month with
    //  the last city being j

    dp[0][0] = d[0];
    dp[0][1] = m[0];

    for (int i = 1; i < n; ++i) {
        dp[i][0] = min(d[i] + dp[i - 1][0], m[i] + dp[i - 1][1] + M);
        dp[i][1] = min(m[i] + dp[i - 1][1], d[i] + dp[i - 1][0] + M);
    }

    return min(dp[n - 1][0], dp[n - 1][1]);
}
// Time Complexity (TC): O(n)
// Space Complexity (SC): O(n) for the dp array