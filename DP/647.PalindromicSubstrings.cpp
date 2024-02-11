#include <bits/stdc++.h>
using namespace std; 
//tabulation-O(n^2)
class Solution {
public:
    int countSubstrings(string s) {
        // i,j both inclusive of the characters at index i and j
        //dp[i][j]=true => s[i:j] is a palind
        //dp[i][j]=false => s[i:j] is not a palind
        int n=s.length();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int ctr=0;
        for(int l=1;l<=n;l++){
            for(int i=0;i+l-1<n;i++){
                int j=i+l-1;
                if(i==j){ //len of substr=1 =>always a palind
                    dp[i][j]=true;
                }else if(i+1==j){//len=2
                    dp[i][j]=(s[i]==s[j]);
                }else{//len>2
                    dp[i][j]=(s[i]==s[j] && dp[i+1][j-1]);
                }
                if(dp[i][j]==true) ctr++;
            }
        }
        return ctr;
    }
};
// // T-O(n^2)-memoi
// class Solution {
// public:
//     int dp[1001][1001];
//     bool check(string &s,int i,int j){
//         if(i>j) return true;
//         if(dp[i][j]!=-1) return dp[i][j];
//         if(s[i]==s[j]){
//             return dp[i][j]=check(s,i+1,j-1);
//         }
//         return dp[i][j]=false;
//     }
//     int countSubstrings(string s) {
//         int n=s.length();
//         memset(dp,-1,sizeof(dp));
//         // dp[i][j]=-1 not yet found
//         // dp[i][j]=0 false
//         // dp[i][j]=1 true
//         int ctr=0;
//         for(int i=0; i < n;i++){
//             for(int j=i;j<n;j++){
//                 if(check(s,i,j)){//if substr is palindrom
//                     ctr++;
//                 }
//             }
//         }
//         return ctr;
//     }
// };