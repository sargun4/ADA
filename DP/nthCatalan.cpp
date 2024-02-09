 
#include <bits/stdc++.h>
using namespace std;
 
class Solution{
    public:
    //Function to find the nth catalan number.
    int findCatalan(int n) {
        if (n == 0) {
            return 1;
        } 
        const int MOD = 1e9 + 7;
        vector<long long> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i]=(dp[i]+(dp[j]*dp[i-j-1])%MOD)%MOD;
            }
        } 
        return  (dp[n]);
    }
};
// class Solution:
//     def findCatalan(self, n: int) -> int:
//         if n == 0:
//             return 1
        
//         MOD = int(1e9 + 7)
//         dp = [0] * (n + 1)
//         dp[0] = dp[1] = 1
        
//         for i in range(2, n + 1):
//             for j in range(i):
//                 dp[i] = (dp[i] + (dp[j] * dp[i - j - 1])) % MOD
        
//         return dp[n]