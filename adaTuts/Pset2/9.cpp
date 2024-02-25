// 9. If there is a team S of n players, then design an algorithm that counts the number of tuples
// (A, x) such that A ⊆ S, x ∈ A and |A| = k. Same as previous question, dont use n! / (k!(n−k)!)
#include <iostream>
#include <vector>

using namespace std;

// Function to count the number of tuples (A, x) with |A| = k
int countTuples(const vector<int>& S, int k) {
    int n = S.size();

    // Create a 2D vector to store the count of tuples
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    // Base case: There is one way to choose k elements from an empty set
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 1;
    }

    // Fill the dp table using the recurrence relation
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            // Two possibilities: either include the current element or exclude it
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
        }
    }

    // The final result is stored in dp[n][k]
    return dp[n][k];
}

int main() {
    // Example usage
    vector<int> S = {1, 2, 3, 4, 5};
    int k = 3;

    // Call the function to count the number of tuples
    int result = countTuples(S, k);

    // Output the result
    cout << "Number of tuples (A, x) with |A| = " << k << ": " << result << endl;

    return 0;
}
