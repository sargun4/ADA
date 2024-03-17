
#include<bits/stdc++.h>
using namespace std; 
//tab 

class Solution{
public:
    bool wildCard(string pattern, string str) {
        int n = pattern.size();
        int m = str.size(); 
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        dp[0][0] = true;

        // Initialize dp[i][0] for patterns consisting of only asterisks
        for (int i = 1; i <= n; i++) {
            if (pattern[i - 1] == '*') {
                dp[i][0] = dp[i - 1][0];
            } else {
                break;
            }
        } 
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(pattern[i - 1] == str[j - 1] || pattern[i - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if(pattern[i - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[n][m];
    }
};


//memo
// class Solution{
// public:
//     bool isMatch(string pattern, string str, int i, int j, vector<vector<int>>& dp) {
//         if (i < 0 && j < 0) // both strings exhausted, match
//             return true;
//         if (i < 0) // pattern exhausted, but string still has characters
//             return false;
//         if (j < 0) { // string exhausted, check if remaining pattern characters are all *
//             for (int k = 0; k <= i; k++) {
//                 if (pattern[k] != '*') return false;
//             }
//             return true;
//         }
//         if (dp[i][j] != -1) return dp[i][j];
        
//         if (pattern[i] == str[j] || pattern[i] == '?')
//             return dp[i][j] = isMatch(pattern, str, i - 1, j - 1, dp);
        
//         if (pattern[i] == '*')
//             return dp[i][j] = isMatch(pattern, str, i - 1, j, dp) || isMatch(pattern, str, i, j - 1, dp);
        
//         return dp[i][j] = false;
//     }

//     bool wildCard(string pattern, string str) {
//         int n = pattern.size();
//         int m = str.size();
//         vector<vector<int>> dp(n, vector<int>(m, -1));
//         return isMatch(pattern, str, n - 1, m - 1, dp);
//     }
// };

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return isMatchUtil(s, p, n, m, dp);
    }

    bool isMatchUtil(string& s, string& p, int i, int j, vector<vector<int>>& dp) {
        if (i == 0 && j == 0) // Both strings are empty, match
            return true;
        if (j == 0) // Pattern is empty, but string still has characters
            return false;
        if (i == 0) { // String is empty, but pattern still has characters
            for (int k = 0; k < j; k++) {
                if (p[k] != '*') // If remaining pattern characters are not '*', no match
                    return false;
            }
            return true; // If only '*'s are remaining, match
        }
        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
            return dp[i][j] = isMatchUtil(s, p, i - 1, j - 1, dp);

        if (p[j - 1] == '*')
            return dp[i][j] = isMatchUtil(s, p, i - 1, j, dp) || isMatchUtil(s, p, i, j - 1, dp);

        return dp[i][j] = false;
    }
};
