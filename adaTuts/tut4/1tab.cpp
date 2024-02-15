#include <iostream>
#include <vector>

bool canPartitionIntoThree(const std::vector<int>& A) {
    int n = A.size();
    int totalSum = 0;

    for (int num : A) {
        totalSum += num;
    }

    // Check if the total sum is divisible by 3
    if (totalSum % 3 != 0) {
        return false;
    }

    int targetSum = totalSum / 3;

    // Initialize a 2D DP table to store intermediate results
    std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(targetSum + 1, false));

    // Base case: an empty set can have a sum of 0
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = true;
    }

    // Fill the DP table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= targetSum; ++j) {
            dp[i][j] = dp[i - 1][j];

            if (j >= A[i - 1]) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - A[i - 1]];
            }
        }
    }

    // The answer is in the bottom-right cell of the DP table
    return dp[n][targetSum];
}

int main() {
    std::vector<int> A = {1, 6, 11, 5, 2, 3};

    if (canPartitionIntoThree(A)) {
        std::cout << "Can be partitioned into three subsets with equal sum." << std::endl;
    } else {
        std::cout << "Cannot be partitioned into three subsets with equal sum." << std::endl;
    }

    return 0;
}
