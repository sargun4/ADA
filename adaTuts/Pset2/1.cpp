// There is a reality show where there are a collection of n songs. You know all the songs, all
// the judges, and your own dancing ability pretty well. For every k ∈ {1, 2, . . . , n}, you know
// that if you dance to the k-th song, then you will earn Score[k] points, but then you will be
// physically unable to dance at the next Wait[k] songs, i.e. (k + 1)-th song to (k + Wait[k])-th
// songs. The dancer with the highest total score at the night wins the contest. So you want
// your total score to be as high as possible.
// Design a polynomial-time algorithm that computes the maximum total score you can achieve.


#include <bits/stdc++.h>
using namespace std;
 
//rec-Time Complexity (TC): Exponential, O(2^n)
// Space Complexity (SC): O(n) for the recursive call stack
int recursiveMaxTotalScore(const vector<int>& Score, const vector<int>& Wait, int k) {
    if (k <= 0) {
        return 0;
    }

    int maxScore = Score[k - 1];
    for (int j = 1; j <= min(Wait[k - 1], k - 1); ++j) {
        maxScore = max(maxScore, Score[k - 1] + recursiveMaxTotalScore(Score, Wait, k - j - 1));
    }

    return maxScore;
}

int maxTotalScoreRecursive(const vector<int>& Score, const vector<int>& Wait) {
    int n = Score.size();
    return recursiveMaxTotalScore(Score, Wait, n);
}
  

  //memo-Time Complexity (TC): O(n^2) (due to memoization)
// Space Complexity (SC): O(n) for the memoization table and O(n) for the recursive call stac

int memoizedMaxTotalScore(const vector<int>& Score, const vector<int>& Wait, int k, unordered_map<int, int>& memo) {
    if (k <= 0) {
        return 0;
    }

    if (memo.find(k) != memo.end()) {
        return memo[k];
    }

    int maxScore = Score[k - 1];
    for (int j = 1; j <= min(Wait[k - 1], k - 1); ++j) {
        maxScore = max(maxScore, Score[k - 1] + memoizedMaxTotalScore(Score, Wait, k - j - 1, memo));
    }

    memo[k] = maxScore;
    return maxScore;
}
int maxTotalScoreMemoized(const vector<int>& Score, const vector<int>& Wait) {
    int n = Score.size();
    unordered_map<int, int> memo;
    return memoizedMaxTotalScore(Score, Wait, n, memo);
}
 
//tab-Time Complexity (TC): O(n^2)
// Space Complexity (SC): O(n) for the dp array
int maxTotalScore(const vector<int>& Score, const vector<int>& Wait) {
    int n = Score.size();
    vector<int> dp(n + 1, 0); // dp[i] stores the maximum total score up to the i-th song

    for (int k = 1; k <= n; ++k) {
        dp[k] = Score[k - 1]; // Initialize dp[k] with the score of dancing to the k-th song

        for (int j = 1; j <= min(Wait[k - 1], k - 1); ++j) {
            dp[k] = max(dp[k], dp[k - j - 1] + Score[k - 1]);
        }
    }

    return *max_element(dp.begin(), dp.end());
}