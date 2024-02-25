#include <bits/stdc++.h>
using namespace std;
 
class Solution{
public: 
    int matrixMultiplication(int n, int arr[]){
        vector<vector<int>> dp(n,vector<int>(n+1,0));
        for(int i = 1; i < n; i++)
            dp[i][i] = 0;
 
        // L is chain length.
        for (int L = 2; L < n; L++) {
            for (int i = 1; i < n - L + 1; i++){
                int j = i + L - 1;
                dp[i][j] = INT_MAX;
                for(int k = i; k <j; k++) {
                    // q = cost/scalar multiplications
                    int q = dp[i][k] + dp[k + 1][j]+ arr[i - 1] * arr[k] * arr[j];
                    if (q < dp[i][j])
                        dp[i][j] = q;
                }
            }
        }
    
        return dp[1][n - 1];
    }
};