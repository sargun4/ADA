
#include<bits/stdc++.h>
using namespace std; 
 
class Solution{
    public:    
    int longestCommonSubstr (string S1, string S2, int n, int m){
        // int dp[n+1][m+1];
        int ans=0;
        vector<int> prev(m+1,0),curr(m+1,0);
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0||j==0){
                    curr[j]=0;
                }else if(S1[i-1]==S2[j-1]){
                    curr[j]=prev[j-1]+1;
                    ans = max(ans, curr[j]);
                }else{
                    curr[j]=0;
                }
            }
            prev=curr;
        }
        return ans;
    }
};
// class Solution{
//     public:    
//     int longestCommonSubstr (string S1, string S2, int n, int m){
//         int dp[n+1][m+1];
//         int ans=0;
//         for(int i=0;i<=n;i++){
//             for(int j=0;j<=m;j++){
//                 if(i==0||j==0){
//                     dp[i][j]=0;
//                 }else if(S1[i-1]==S2[j-1]){
//                     dp[i][j]=dp[i-1][j-1]+1;
//                     ans = max(ans, dp[i][j]);
//                 }else{
//                     dp[i][j]=0;
//                 }
//             }
//         }
//         return ans;
//     }
// };
