// Max Sum without Adjacents

#include <bits/stdc++.h>
using namespace std;
//memo
// class Solution{
// public:	
// 	int solve(int*arr,int i,vector<int> &dp){
//         if(i==0) return arr[i];
//         if(i<0) return 0;
//         if(dp[i]!=-1){
//             return dp[i];
//         }
//         int take=solve(arr,i-2,dp)+arr[i];
//         int skip=solve(arr,i-1,dp);
//         return dp[i]=max(take,skip);
//     }
// 	int findMaxSum(int*arr, int n) {
// 	    vector<int> dp(n,-1);
//         return solve(arr,n-1,dp);
// 	}
// };

// //tab
// class Solution{
// public:	
// 	int findMaxSum(int*arr, int n) {
// 	    vector<int> dp(n,-1);
//         dp[0]=arr[0];
//         for(int i=1;i<n;i++){
//             int take=arr[i]+dp[i-2];
//             int skip=dp[i-1];
//             dp[i]=max(take,skip);
//         }
//         return dp[n-1];
// 	}
// };

//space opt
class Solution{
public:	
	int findMaxSum(int*arr, int n) {
        int prev=arr[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int take=arr[i]+prev2;
            int skip=0+prev;

            int curr=max(take,skip);
            prev2=prev;
            prev=curr;
        }
        return prev;
	}
};
