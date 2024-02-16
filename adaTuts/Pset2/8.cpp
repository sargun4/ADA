#include <iostream>
#include <vector>

using namespace std;

// Function to count subsets of size k using recursion and dynamic programming
int countSubsetsOfSizeK(const vector<int>& A, int n, int k, vector<vector<int>>& memo) {
    // Base cases
    if (k == 0 || k == n) {
        return 1;
    }

    // Check if the result is already memoized
    if (memo[n][k] != -1) {
        return memo[n][k];
    }

    // Recursively calculate the count
    int count = countSubsetsOfSizeK(A, n - 1, k - 1, memo) + countSubsetsOfSizeK(A, n - 1, k, memo);

    // Memoize the result
    memo[n][k] = count;

    return count;
}

// Function to initialize memoization table and call the recursive function
int countSubsetsOfSizeKWrapper(const vector<int>& A, int n, int k) {
    // Memoization table
    vector<vector<int>> memo(n + 1, vector<int>(k + 1, -1));

    // Call the recursive function
    return countSubsetsOfSizeK(A, n, k, memo);
}

int main() {
    // Example usage
    vector<int> A = {1, 2, 3, 4, 5};
    int n = A.size();
    int k = 3;

    // Call the function to count subsets of size k
    int result = countSubsetsOfSizeKWrapper(A, n, k);

    // Output the result
    cout << "Number of subsets of size " << k << ": " << result << endl;

    return 0;
}
