 
#include <bits/stdc++.h>
using namespace std; 
class Solution {
public:
    int solve(int i,int j,string s, string t,vector<vector<int>> &dp){
      if(i<0) return j+1;//if string s gets exhausted ,no of ops=j+1
      if(j<0) return i+1; //if string t gets exhausted,no of ops=i+1
      if(dp[i][j]!=-1)return dp[i][j];
      if(s[i]==t[j]) return solve(i-1,j-1,s,t,dp);
      int insert=1+solve(i,j-1,s,t,dp);
      int remove=1+solve(i-1,j,s,t,dp);
      int replace=1+solve(i-1,j-1,s,t,dp);
      return dp[i][j]=min(insert,min(replace,remove));
    }
    int editDistance(string s, string t) {
        int n=s.length(); int m=t.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,s,t,dp);
    }
};  