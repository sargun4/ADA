
#include <bits/stdc++.h>
using namespace std;
// Partition A Set Into Two Subsets With Minimum Absolute Sum Difference 
// https://www.geeksforgeeks.org/problems/minimum-sum-partition3317/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article
class Solution{
  public:
	int minDifference(int arr[], int n){ 
        int total_sum=0;
        for(int i=0;i<n;i++){
            total_sum+=arr[i];
        }
        int k=total_sum;
        vector<vector<bool>> dp(n,vector<bool>(k+1,0));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        if(arr[0]<=k) dp[0][arr[0]]=true;
        for(int i=1;i<n;i++){
            for(int target=1;target<=k;target++) {
                bool nottake=dp[i-1][target];
                bool take=false;
                if(arr[i]<=target){
                    take=dp[i-1][target-arr[i]];
                }
                dp[i][target]=nottake||take;
            }
        }
        int mini=1e9;
        for(int s1=0;s1<=total_sum/2;s1++){
            if(dp[n-1][s1]==true){
                mini=min(mini,abs((total_sum-s1)-s1));
            }
        }
        return mini;
	} 
};