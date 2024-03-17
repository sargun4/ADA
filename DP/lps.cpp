// Case1: Every single character is a palindrome of length 1
// L(i, i) = 1 (for all indexes i in given sequence)
// Case2: If first and last characters are not same
// If (X[i] != X[j])  L(i, j) = max{L(i + 1, j), L(i, j – 1)} 
// Case3: If there are only 2 characters and both are same
// Else if (j == i + 1) L(i, j) = 2  
// Case4: If there are more than two characters, and first and last characters are same
// Else L(i, j) =  L(i + 1, j – 1) + 2 

#include<bits/stdc++.h>
using namespace std; 
class Solution{
public:
    int lcs(string s,string t){
        int n=s.length(); int m=t.length();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0||j==0){
                    dp[i][j]=0;
                }else if(s[i-1]==t[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else{
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[n][m];
    }
    int longestPalinSubseq(string A) {
        string t=A;
        reverse(t.begin(),t.end());
        return lcs(A,t);
    }
};
 