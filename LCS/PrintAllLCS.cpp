#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    set<string> st; // Set to store unique lcs'
    void helper_print(string s, string t, int i, int j, string &temp, vector<string> & ans, int ctr){
        if(ctr == 0){
            if(st.find(temp) == st.end()){ //if we dont find any other subseq=temp 
            // If the subsequence is unique
                st.insert(temp);
                ans.push_back(temp);
            }
            return;
        }
        if(i >= s.size() || j >= t.size()) return;//If either condition is true, it means we have exhausted one of the input strings, 
        // and there are no more characters to compare 
        for(int row=i;row<s.size();row++){
            for(int col=j;col<t.size();col++){
                if(s[row] == t[col]){
                    temp.push_back(s[row]);
                    helper_print(s, t, row+1, col+1, temp, ans, ctr-1);
                    temp.pop_back(); //backtracking
                }
            }
        }
    }
    vector<string> all_longest_common_subsequences(string s, string t){
        int n = s.size();
        int m = t.size();
        int dp[n+1][m+1];
	    for(int i=0;i<n+1;i++){
	        for(int j=0;j<m+1;j++){
	            if(i == 0 || j == 0){
	                dp[i][j] = 0;
	            }
	        }
	    }
	    for(int i=1;i<n+1;i++){
	        for(int j=1;j<m+1;j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        } 
        int lcs_length = dp[n][m];  
        vector<string> ans;
        string temp = "";
        helper_print(s, t, 0, 0, temp, ans, lcs_length);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
// The expected time complexity of the given code is O(n^4), and the expected space complexity is O(K * n), where K is a constant less than n.

// Let's break down the complexities:

// Time Complexity (O(n^4)):

// The dynamic programming matrix dp is of size (n + 1) x (m + 1), where n and m are the lengths of strings s and t, respectively.
// The initialization of the matrix takes O(n * m) time.
// The nested loops for filling the matrix take O(n * m) time.
// The backtracking function helper_print explores all possible subsequences, and in the worst case, it can iterate over all elements in the matrix (n * m) for each cell. So, the overall time complexity of the backtracking part is O(n^2 * m^2).
// Combining these, the overall time complexity is O(n * m) + O(n * m) + O(n^2 * m^2), which simplifies to O(n^4).
// Space Complexity (O(K * n)):

// The dynamic programming matrix dp requires O(n * m) space.
// The recursive backtracking uses additional space for the temp string, which can have a maximum length of the longest common subsequence (LCS). In the worst case, the LCS can be of length n, so the space complexity is O(n).
// The set st is used to store unique subsequences. In the worst case, it may store all unique subsequences, but since it's a set, it won't store duplicates. The space complexity is related to the number of unique subsequences, and the worst case is O(K * n) where K is a constant less than n.
// The space complexity is dominated by the dynamic programming matrix and the set.




// // We construct dp[m+1][n+1] table as discussed in the previous post and traverse the 2D array starting from dp[m][n]. For current cell dp[i][j] in the matrix,
// // a) If the last chars of X and Y are same (i.e. X[i-1] == Y[j-1]), then the char must be present in all LCS of substring X[0…i-1] and Y[0..j-1]. We simply recurse for dp[i-1][j-1] in the matrix and append current char to all LCS possible of substring X[0…i-2] and Y[0..j-2].
// // b) If the last chars of X and Y are not same (i.e. X[i-1] != Y[j-1]), then LCS can be constructed from either top side of the matrix (i.e. dp[i-1][j]) or from left side of matrix (i.e. dp[i][j-1]) depending upon which value is greater. If both the values are equal(i.e. dp[i-1][j] == dp[i][j-1]), then it will be constructed from both sides of matrix. So based on values at dp[i-1][j] and dp[i][j-1], we go in direction of greater value or go in both directions if the values are equal.
// // Below is recursive implementation of above idea – 




// // Maximum string length
// #define N 100
// int dp[N][N];
// /* Returns set containing all LCS for X[0..m-1], Y[0..n-1] */
// set<string> findLCS(string X, string Y, int m, int n){
// 	set<string> s;//set to store possible LCS
// 	// If we reach end of either string, return empty set
// 	if (m == 0 || n == 0){
// 		s.insert("");
// 		return s;
// 	}
// 	// If the last chars of X and Y are same
// 	if (X[m - 1] == Y[n - 1]){
// 		// recurse for X[0..m-2] and Y[0..n-2] in the matrix
// 		set<string> temp = findLCS(X, Y, m - 1, n - 1);
// 		// append current char to all possible LCS of substring X[0..m-2] and Y[0..n-2].
// 		for (string str : temp)
// 			s.insert(str + X[m - 1]);
// 	}
// 	// If the last chars of X and Y are not same
// 	else{
// 		// If LCS can be constructed from top side of
// 		// the matrix, recurse for X[0..m-2] and Y[0..n-1]
// 		if (dp[m - 1][n] >= dp[m][n - 1])
// 			s = findLCS(X, Y, m - 1, n);
// 		// If LCS can be constructed from left side of
// 		// the matrix, recurse for X[0..m-1] and Y[0..n-2]
// 		if (dp[m][n - 1] >= dp[m - 1][n]){
// 			set<string> temp = findLCS(X, Y, m, n - 1);
// 			// merge two sets if dp[m-1][n] == dp[m][n-1]
// 			// Note s will be empty if dp[m-1][n] != dp[m][n-1]
// 			s.insert(temp.begin(), temp.end());
// 		}
// 	}
// 	return s;
// }
// /* Returns length of LCS for X[0..m-1], Y[0..n-1] */
// int LCS(string X, string Y, int m, int n){
// 	// Build dp[m+1][n+1] in bottom up fashion
// 	for (int i = 0; i <= m; i++){
// 		for (int j = 0; j <= n; j++){
// 			if (i == 0 || j == 0)
// 				dp[i][j] = 0;
// 			else if (X[i - 1] == Y[j - 1])
// 				dp[i][j] = dp[i - 1][j - 1] + 1;
// 			else
// 				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
// 		}
// 	}
// 	return dp[m][n];
// }
// // Time Complexity: It will be exponential because we are using recursion to find all possible LCS. 

// // Space Complexity: O(n*n) 
// int main(){
// 	string X = "AGTGATG";
// 	string Y = "GTTAG";
// 	int m = X.length();
// 	int n = Y.length();
// 	cout << "LCS length is " << LCS(X, Y, m, n) << endl;
// 	set<string> s = findLCS(X, Y, m, n);
// 	for (string str : s)
// 		cout << str << endl;
// 	return 0;
// }
