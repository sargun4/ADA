 
 


#include <bits/stdc++.h>
using namespace std; 
// // To make use of recursive calls, this
// // function must return two things:
// // 1) Length of LIS ending with element
// // arr[n-1].
// // We use max_ending_here for this purpose
// // Overall maximum as the LIS may end with
// // an element before arr[n-1] max_ref is
// // used this purpose.
// // The value of LIS of full array of size
// // n is stored in *max_ref which is
// // our final result
// int f(int idx, int prev_idx, int n, int a[],
// 	vector<vector<int> >& dp){
// 	if (idx == n) {
// 		return 0;
// 	}
// 	if (dp[idx][prev_idx + 1] != -1) {
// 		return dp[idx][prev_idx + 1];
// 	}
// 	int notTake = 0 + f(idx + 1, prev_idx, n, a, dp);
// 	int take = INT_MIN;
// 	if (prev_idx == -1 || a[idx] > a[prev_idx]) {
// 		take = 1 + f(idx + 1, idx, n, a, dp);
// 	}
// 	return dp[idx][prev_idx + 1] = max(take, notTake);
// }
// int longestSubsequence(int n, int a[]){
// 	vector<vector<int> > dp(n + 1, vector<int>(n + 1, -1));
// 	return f(0, -1, n, a, dp);
// }


// //dp-Due to optimal substructure and overlapping subproblem property, we can also utilise Dynamic programming to solve
// //  the problem. Instead of memoization, we can use the nested loop to implement the recursive relation.

// // The outer loop will run from i = 1 to N and the inner loop will run from j = 0 to i and use the recurrence relation to solve the problem.

// // lis() returns the length of the longest
// // increasing subsequence in arr[] of size n
// int lis(int arr[], int n){
// 	int lis[n];
// 	lis[0] = 1;
// 	// Compute optimized LIS values in
// 	// bottom up manner
// 	for (int i = 1; i < n; i++) {
// 		lis[i] = 1;
// 		for (int j = 0; j < i; j++)
// 			if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
// 				lis[i] = lis[j] + 1;
// 	}
// 	// Return maximum value in lis[]
// 	return *max_element(lis, lis + n);
// }
