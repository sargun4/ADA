// https://www.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
#include <bits/stdc++.h>
using namespace std;
//tab
class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mat){
        if (n == 0 || m == 0) return 0;
         if (n == 1 || m == 1) {
            // If the matrix has only one row or one column,
            // check if there is any 1 in the entire matrix
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    if (mat[i][j] == 1) return 1;
                }
            }
            // If no 1 is found, return 0 (no square can be formed)
            return 0;
        }
        int ans=0;
        vector<vector<int>> dp=mat;//copy
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 && j==m-1){//bottom left cell
                    dp[i][j]=mat[i][j];
                    ans = max(ans, dp[i][j]);
                }else if(i==n-1){//last row
                    dp[i][j]=mat[i][j];
                    ans = max(ans, dp[i][j]);

                }else if(j==m-1){//last col
                    dp[i][j]=mat[i][j];
                    ans = max(ans, dp[i][j]);

                }else{
                    if(mat[i][j]==0){
                        dp[i][j]=0;
                    }else{
                        int right=dp[i][j+1];
                        int down=dp[i+1][j];
                        int rd=dp[i+1][j+1];
                        int mini=min(right,min(down,rd));
                        dp[i][j]=mini+1;
                        if(dp[i][j]>ans){
                            ans=dp[i][j];
                        }
                    }
                }
            }
        }
        return ans;
    }
};
//memo- 


#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSquare(int n, int m, vector<vector<int>>& mat) {
        int maxSide = 0;
        unordered_map<string, int> memo;
        memoizedHelper(mat, n, m, 0, 0, maxSide, memo);
        return maxSide * maxSide;
    }

private:
    int memoizedHelper(vector<vector<int>>& mat, int n, int m, int i, int j, int& maxSide, unordered_map<string, int>& memo) {
        if (i == n || j == m) {
            return 0;
        }

        string key = to_string(i) + "-" + to_string(j);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        if (mat[i][j] == 1) {
            int right = memoizedHelper(mat, n, m, i, j + 1, maxSide, memo);
            int down = memoizedHelper(mat, n, m, i + 1, j, maxSide, memo);
            int diagonal = memoizedHelper(mat, n, m, i + 1, j + 1, maxSide, memo);

            int minSide = min(right, min(down, diagonal)) + 1;
            maxSide = max(maxSide, minSide);

            memo[key] = minSide;
            return minSide;
        }

        memo[key] = 0;
        return 0;
    }
};
