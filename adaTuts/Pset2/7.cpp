// 7. Suppose that you are given an array A[1, 2, . . . , n] of positive integers. An increasing back and
// fourth sequence is a sequence of indices J[1, 2, . . . , `] satisfying the following properties.
// • 1 ≤ J[i] ≤ n for all j.


// • A[J[i]] < A[J[i + 1]] for all i < `.
// • If J[i] is even, then J[i + 1] > J[i].
// • If J[i] is odd, then J[i + 1] < J[i].
// For example, if the numbers in the input array A appear in this order 1, 1, 8, 7, 5, 6, 3, 6, 4, 4, 8, 3,
// 9, 1, 2, 2, 3, 9, 4, 0, then a longest increasing back and fourth sequence is 0(20), 1(1), 2(15),
// 3(18), 4(10), 6(6), 7(4), 8(3), 9(13).
//memo-
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

unordered_map<string, int> memo;

int memoizedLongestIncreasingBF(const vector<int>& A, int i, int prevIndex, bool isEven) {
    if (i == A.size()) {
        return 0;
    }

    string key = to_string(i) + "_" + to_string(prevIndex) + "_" + to_string(isEven);
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }

    int lengthIfExcluded = memoizedLongestIncreasingBF(A, i + 1, prevIndex, isEven);

    int lengthIfIncluded = 0;
    if ((isEven && A[i] > A[prevIndex]) || (!isEven && A[i] < A[prevIndex])) {
        lengthIfIncluded = 1 + memoizedLongestIncreasingBF(A, i + 1, i, !isEven);
    }

    memo[key] = max(lengthIfExcluded, lengthIfIncluded);
    return memo[key];
}

vector<int> findLongestIncreasingBFMemo(const vector<int>& A) {
    int maxLength = 0;
    int endIndex = 0;
    int n = A.size();

    for (int i = 0; i < n; ++i) {
        int length = memoizedLongestIncreasingBF(A, i + 1, i, true) + 1; // Adding 1 for the current element
        if (length > maxLength) {
            maxLength = length;
            endIndex = i;
        }
    }

    vector<int> result;
    int currentIndex = endIndex;
    int currentLength = maxLength;

    while (currentLength > 0) {
        result.push_back(currentIndex);
        currentLength--;

        if (currentLength > 0) {
            for (int j = currentIndex - 1; j >= 0; --j) {
                if (A[j] < A[currentIndex]) {
                    currentIndex = j;
                    break;
                }
            }
        }
    }

    reverse(result.begin(), result.end()); // Reverse to get the correct order
    return result;
}

int main() {
    // Example usage
    vector<int> A = {1, 1, 8, 7, 5, 6, 3, 6, 4, 4, 8, 3, 9, 1, 2, 2, 3, 9, 4, 0};

    // Call the function to find the longest increasing back-and-forth sequence
    vector<int> result = findLongestIncreasingBFMemo(A);

    // Output the result
    cout << "Longest increasing back-and-forth sequence: ";
    for (int i : result) {
        cout << i << "(" << A[i] << ") ";
    }

    return 0;
}




// 
// Function to find the longest increasing back-and-forth sequence
vector<int> longestIncreasingBackAndForth(const vector<int>& A) {
    int n = A.size();
    vector<int> evenDP(n, 1);  // Length of increasing back-and-forth sequence ending at even index
    vector<int> oddDP(n, 1);   // Length of increasing back-and-forth sequence ending at odd index

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (A[i] > A[j]) {
                evenDP[i] = max(evenDP[i], oddDP[j] + 1);
            } else if (A[i] < A[j]) {
                oddDP[i] = max(oddDP[i], evenDP[j] + 1);
            }
        }
    }

    // Find the maximum length and the corresponding index
    int maxLength = 0;
    int endIndex = 0;
    for (int i = 0; i < n; ++i) {
        if (evenDP[i] > maxLength) {
            maxLength = evenDP[i];
            endIndex = i;
        }
        if (oddDP[i] > maxLength) {
            maxLength = oddDP[i];
            endIndex = i;
        }
    }

    // Reconstruct the longest increasing back-and-forth sequence
    vector<int> res;
    int currentIndex = endIndex;
    int currentLength = maxLength;

    while (currentLength > 0) {
        res.push_back(currentIndex);
        currentLength--;

        if (currentLength > 0) {
            if (currentIndex % 2 == 0) { // Even index
                for (int j = currentIndex - 1; j >= 0; --j) {
                    if (evenDP[j] == currentLength && A[j] < A[currentIndex]) {
                        currentIndex = j;
                        break;
                    }
                }
            } else { // Odd index
                for (int j = currentIndex - 1; j >= 0; --j) {
                    if (oddDP[j] == currentLength && A[j] > A[currentIndex]) {
                        currentIndex = j;
                        break;
                    }
                }
            }
        }
    }

    reverse(res.begin(), res.end()); // Reverse to get the correct order

    return res;
}

int main() {
    vector<int> A = {1, 1, 8, 7, 5, 6, 3, 6, 4, 4, 8, 3, 9, 1, 2, 2, 3, 9, 4, 0};
    vector<int> res = longestIncreasingBackAndForth(A);
    cout << "Longest increasing back-and-forth sequence: ";
    for (int i : res) {
        cout << i << "(" << A[i] << ") ";
    }
    return 0;
}
