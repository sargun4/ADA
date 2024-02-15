#include <iostream>
#include <vector>
#include <unordered_map>

bool canPartitionHelper(const std::vector<int>& A, int n, int sum, std::unordered_map<std::string, bool>& memo) {
    if (n == 0 && sum == 0) {
        return true;
    }

    if (n == 0 || sum < 0) {
        return false;
    }

    // Create a unique key for the current state
    std::string key = std::to_string(n) + "|" + std::to_string(sum);

    // Check if the result is already memoized
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }

    // Try including the current element in the sum
    bool include = canPartitionHelper(A, n - 1, sum - A[n - 1], memo);

    // Try excluding the current element from the sum
    bool exclude = canPartitionHelper(A, n - 1, sum, memo);

    // Memoize the result for the current state
    memo[key] = include || exclude;

    return memo[key];
}

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

    std::unordered_map<std::string, bool> memo;
    return canPartitionHelper(A, n, targetSum, memo);
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
