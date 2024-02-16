

class Solution{
public:
    int mod=1e9+7;
    int nCr(int n, int r){
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(n,r,dp)%mod;
    }
    // mod = 1e9+7 and dp[n+1][n+1] all elements are set to -1    
    int solve(int n, int r,vector<vector<int>> &dp){
        if(n<r){
            return 0;
        }
        if(r == 0 || r == n){
            return 1;
        }
        if(dp[n][r] != -1)
            return dp[n][r];
        return dp[n][r] = (solve(n-1,r-1,dp)+solve(n-1,r,dp))%mod;
    }
};