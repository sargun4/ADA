
#include <bits/stdc++.h>
using namespace std;

//tab
class Solution{
public: 
    int cutRod(int price[], int n) {
        vector<vector<int>> dp(n,vector<int>(n+1,0));
        for(int j=0;j<=n;j++){
            dp[0][j]=j*price[0];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=n;j++){
                int skip=0+dp[i-1][j];
                int take=INT_MIN;
                int rodlen=i+1;
                if(rodlen<=j){
                    take=price[i]+dp[i][j-rodlen];
                }
                dp[i][j]=max(take,skip);
            }
        }
        return dp[n-1][n];
    }
};

// //Time Complexity: O(N^2)
// //Auxiliary Space: O(N) 