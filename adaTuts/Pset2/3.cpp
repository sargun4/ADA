// 3. You are going on a long trip. You start on the road at mile post 0. Along the way there are n
// hotels, at mile posts a1 < a2 < · · · < an, where each ai is measured from the starting point.
// The only places you are allowed to stop are at these hotels, but you can choose which of the
// hotels you stop at. You must stop at the final hotel (at distance an), which is your destination.
// You’d ideally like to travel 250 miles a day, but this may not be possible (depending on
// the spacing of the hotels). If you travel x miles during a day, the penalty for that day is
// (250 − x)^2
// . You want to plan your trip so as to minimize the total penalty – that is, the sum,
// over all travel days, of the daily penalties. Give an efficient algorithm that determines the
// minimum cost of a sequence of hotels at which to stop.


#include <bits/stdc++.h>
using namespace std;

// Recursive Solution (REC):
int recursiveMinPenalty(const vector<int>& hotels, int i) {
    if (i == 0) {
        return pow(250 - hotels[0], 2);
    }

    int minPenalty = INT_MAX;
    for (int j = 0; j < i; ++j) {
        int penalty = recursiveMinPenalty(hotels, j) + pow(250 - (hotels[i] - hotels[j]), 2);
        minPenalty = min(minPenalty, penalty);
    }

    return minPenalty;
}
// Time Complexity (TC): Exponential, O(2^n)
// Space Complexity (SC): O(n) for the recursive call stack


// Memoized Solution (MEMO):
int memoizedMinPenalty(const vector<int>& hotels, int i, unordered_map<int, int>& memo) {
    if (i == 0) {
        return pow(250 - hotels[0], 2);
    }

    if (memo.find(i) != memo.end()) {
        return memo[i];
    }

    int minPenalty = INT_MAX;
    for (int j = 0; j < i; ++j) {
        int penalty = memoizedMinPenalty(hotels, j, memo) + pow(250 - (hotels[i] - hotels[j]), 2);
        minPenalty = min(minPenalty, penalty);
    }

    memo[i] = minPenalty;
    return minPenalty;
}
// Time Complexity (TC): O(n^2) (due to memoization)
// Space Complexity (SC): O(n) for the memoization table and O(n) for the recursive call stack


// Tabulation Solution (TAB):
int minPenalty(const vector<int>& hotels) {
    int n = hotels.size();
    vector<int> dp(n, INT_MAX); // dp[i] stores the minimum penalty up to the i-th hotel

    dp[0] = pow(250 - hotels[0], 2);

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            dp[i] = min(dp[i], dp[j] + pow(250 - (hotels[i] - hotels[j]), 2));
        }
    }

    return dp[n - 1];
}
// Time Complexity (TC): O(n^2)
// Space Complexity (SC): O(n) for the dp array