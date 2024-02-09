#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int MOD = 1000000007;

    // Function to count number of ways to reach the nth stair.
    int countWays(int n) {
        int dp[n + 1];
        dp[0] = 1;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
        }

        return dp[n];
    }
};

class Solution{
    public:
    //Function to count number of ways to reach the nth stair 
     //when order does not matter.
    long long countWays(int m){
        long long dp[m + 1];
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= m; i++)  
            dp[i] = (dp[i-2] + 1);
        return dp[m];
    }
};
// //memo-tle-
// int MOD=1000000007;
// class Solution{
//     public:
//     //Function to count number of ways to reach the nth stair.
//     int countWays(int n){
//         if (n==0) return 1;//only 1 way if 0th stair
//         if (n<0) return 0;
//         vector<int> dp(n + 1,-1);
//         if(dp[n]!=-1){
//             return dp[n];
//         }
//         dp[n]=(countWays(n-1)+countWays(n-2))%MOD;
//         return dp[n];
//     }
// };

//  int findStep(int n)
//     {
//         if (n == 0)
//             return 1;
//         else if (n < 0)
//             return 0;
 
//         else
//             return findStep(n - 3) + findStep(n - 2)
//                    + findStep(n - 1);
//     } 

// // Time Complexity: O(3^n). 
// // The time complexity of the above solution is exponential, a close upper bound will be O(3n). From each state, 3 recursive function are called. So the upperbound for n states is O(3n).
// // Space Complexity: O(N). 
// // Auxillary Space required by the recursive call stack is O(depth of recursion tree).

