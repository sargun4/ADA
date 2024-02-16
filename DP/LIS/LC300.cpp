// //memoization-O(n^2) since dp[n+1][n+1]
// #include <bits/stdc++.h>
// using namespace std;
// class Solution {
// public:
//     int n;
//     int dp[2501][2501];
//     int solve(vector<int>& nums,int i,int prev){
//         if(i>=n){ //out of bounds
//             return 0;
//         }
//         if(prev!=-1 && dp[i][prev]!=-1){
//             return dp[i][prev];
//         }
//         int take=0;
//         if(prev==-1||nums[i]>nums[prev]){ //take 
//             take=1+solve(nums,i+1,i);
//         }
//         int skip=solve(nums,i+1,prev);
        
//         if(prev!=-1){
//             dp[i][prev]=max(take,skip);
//         }
//         return max(take,skip);
//     }
//     int lengthOfLIS(vector<int>& nums) {
//         n=nums.size();
//         memset(dp,-1,sizeof(dp));
//         return solve(nums,0,-1);//curridx=0,previdx=-1
//     }
// };


//tabulation-O(n^2)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> t(n,1);
        //t[i]=LIS ending at ith idx;
        int maxLIS=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    t[i]=max(t[i],t[j]+1);
                }
            }       
            maxLIS=max(maxLIS,t[i]);
        }
        return maxLIS;
    }
};