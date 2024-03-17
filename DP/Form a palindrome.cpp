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
    int findMinInsertions(string S){
        return S.size()-longestPalinSubseq(S);
    }
};