//  Operators
//     &   ---> boolean AND
//     |   ---> boolean OR
//     ^   ---> boolean XOR
// Count the number of ways we can parenthesize the expression so that the value of expression
//  evaluates to true.
#include <bits/stdc++.h>
using namespace std; 
#define MOD 1003
class Solution {
public:
    long long f(int i, int j, int isTrue, string &exp,vector<vector<vector<long long>>> &dp){
        if (i > j) return 0;
        if (i == j) {
            if (isTrue) return exp[i] == 'T';
            else return exp[i] == 'F';
        }
        if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue];
        long long ways = 0;
        for (int idx = i + 1; idx <= j - 1; idx += 2) {
            long long leftT = f(i, idx - 1, 1, exp,dp);
            long long leftF = f(i, idx - 1, 0, exp,dp);
            long long rightT = f(idx + 1, j, 1, exp,dp);
            long long rightF = f(idx + 1, j, 0, exp,dp);
            if (exp[idx] == '&') {
                if (isTrue) ways = (ways + ((leftT * rightT) % MOD)) % MOD;
                else ways = (ways + (((leftF * rightT) % MOD) + ((leftT * rightF) % MOD) + ((leftF * rightF) % MOD)) % MOD) % MOD;
            } else if (exp[idx] == '|') {
                if (isTrue) ways = (ways + (((leftT * rightT) % MOD) + ((leftF * rightT) % MOD) + ((leftT * rightF) % MOD))) % MOD;
                else ways = (ways + ((leftF * rightF) % MOD)) % MOD;
            } else { // exp[idx] == '^' xor
                if (isTrue) ways = (ways + (((leftT * rightF) % MOD) + ((leftF * rightT) % MOD))) % MOD;
                else ways = (ways + (((leftT * rightT) % MOD) + ((leftF * rightF) % MOD))) % MOD;
            }
        }
        return dp[i][j][isTrue]=ways;
    }

    int countWays(int n, string s) {
        vector<vector<vector<long long>>> dp(n,vector<vector<long long>>(n,vector<long long>(2,-1)));  
        return static_cast<int>(f(0, n - 1, 1, s,dp));
    }
}; 
