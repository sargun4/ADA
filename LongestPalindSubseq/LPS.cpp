// Time Complexity: O(|S|*|S|).
// Auxiliary Space: O(|S|*|S|).
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalinSubseq(string A) {
        int n = A.length();
        string B(A.rbegin(),A.rend()); // reverse of string A;
        vector<vector<int>> dp(n+1,vector<int> (n+1));
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(A[i-1] == B[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[n][n];
    }
};
// The time complexity of this function is O(n^2), where n is the length of the input string, because it needs to fill all entries in the dp vector. The space complexity is also O(n^2), because it needs to store the vector.

// 4. Space optimization
int longestPalinSubseq(string A) {
        int n = A.length();
        string B(A.rbegin(),A.rend()); 
        vector<int> prev(n+1),curr(n+1);
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(A[i-1] == B[j-1]){
                    curr[j] = 1 + prev[j-1];
                }
                else{
                    curr[j] = max(curr[j-1],prev[j]);
                }
            }
            prev = curr;
        }
        return prev[n];
    }