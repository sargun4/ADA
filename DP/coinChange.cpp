// Recurrence Relation:
// count(coins,n,sum) = count(coins,n,sum-count[n-1]) + count(coins,n-1,sum)

// For each coin, there are 2 options.

// Include the current coin: Subtract the current coin’s denomination from the target sum and call the count function recursively with the updated sum and the same set of coins i.e., count(coins, n, sum – coins[n-1] )
// Exclude the current coin: Call the count function recursively with the same sum and the remaining coins. i.e., count(coins, n-1,sum ).
// Base case:

// If the target sum (sum) is 0, there is only one way to make the sum, which is by not selecting any coin. So, count(0, coins, n) = 1.
// If the target sum (sum) is negative or no coins are left to consider (n == 0), then there are no ways to make the sum, so count(sum, coins, 0) = 0.

#include <bits/stdc++.h>
using namespace std;
// //rec
// int count(int coins[], int n, int sum){
// 	// If sum is 0 then there is 1 solution
// 	// (do not include any coin)
// 	if (sum == 0)
// 		return 1;
// 	// If sum is less than 0 then nosolution exists
// 	if (sum < 0)
// 		return 0;
// 	// If there are no coins and sum is greater than 0, then no solution exist
// 	if (n <= 0)
// 		return 0;
// 	// count is sum of solutions (i)
// 	// including coins[n-1] (ii) excluding coins[n-1]
// 	return count(coins, n, sum - coins[n - 1])
// 		+ count(coins, n - 1, sum);
// }

// //tab
// int count(int coins[], int n, int sum){
// 	// If sum is 0 then there is 1 solution
// 	// (do not include any coin)
// 	if (sum == 0)
// 		return 1;
// 	// If sum is less than 0 then nosolution exists
// 	if (sum < 0)
// 		return 0;
// 	// If there are no coins and sum is greater than 0, then no solution exist
// 	if (n <= 0)
// 		return 0;
// 	// count is sum of solutions (i)
// 	// including coins[n-1] (ii) excluding coins[n-1]
// 	return count(coins, n, sum - coins[n - 1])
// 		+ count(coins, n - 1, sum);
// }
//rec-tle
// class Solution {
//   public:
//     long long int solve(int coins[],int i,int sum){
//         if(i==0){
//             return sum%coins[i]==0;
//         }
//         long long int exclude=solve(coins,i-1,sum);
//         long long int include=0;
//         if(sum>=coins[i]){
//             include=solve(coins,i,sum-coins[i]);
//         }
//         return exclude+include;
//     }
//     long long int count(int coins[], int N, int sum) {
//         return solve(coins,N-1,sum);
//     }
// };

//memo-TC: O(N*sum)
// SC: O(N*sum)+O(sum)
class Solution {
  public:
    long long int solve(int coins[],int i,int sum,vector<vector<long long int>> &dp){
        if(i==0){
            return sum%coins[i]==0;
        }
        if(dp[i][sum]!=-1){
            return dp[i][sum];
        }
        long long int exclude=solve(coins,i-1,sum,dp);
        long long int include=0;
        if(sum>=coins[i]){
            include=solve(coins,i,sum-coins[i],dp);
        }
        return dp[i][sum]=exclude+include;
    }
    long long int count(int coins[], int N, int sum) {
        vector<vector<long long int>> dp(N,vector<long long int>(sum+1,-1));
        return solve(coins,N-1,sum,dp);
    }
};