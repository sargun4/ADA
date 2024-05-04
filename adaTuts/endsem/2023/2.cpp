// q2. Given an m × n matrix of characters, find the length of the longest path in the matrix starting
// from a given character. All characters in the longest path should be increasing and consecutive to each other
// in alphabetical order. We are allowed to search the string in all eight possible directions, i.e., North, West,
// South, East, North-East, North-West, South-East, South-West. For example, consider the following matrix of
// characters:
// The length of the longest path with consecutive characters starting from character C is 6. The longest path is:
// C(2, 2) −→ D(2, 1) −→ E(3, 2) −→ F(2, 3) −→ G(1, 2) −→ H(0, 2)
// [Hint: DP on DAG]
// As the hint suggested, we can view the problem as finding the longest the longest path form a given node in
// the DAG.
// The creation of DAG is straight forward. For each cell (i, j) of the matrix we consider a vertex vi,j in our
// graph like the last question. Now for each cell we check all of it’s neighbouring cells. We put a directed edge
// from vertex vi,j to vertex uk,l if (k, l) is neighbour cell of (i, j) such that the character in (i, j) is smaller than
// the character in (k, l) in alphabetical order. Observe that the created graph say G is a DAG by definition as
// any path in the graph maintains alpabetical ordering. Now the problem is to find the longest path for a given
// node in a DAG.
// Note that, if a neighbour of a cell contains the same character as the cell, we will put directed edge between
// them to any of the direction. This may effect the optimal solution, but this case is acceptable for scoring.
// (+4 for subproblem)
// • Subproblem definition:.
// For a given vertex v let ch(v) denotes children of v. LP (v) denotes the longest path starting form v in
// the graph ∀v ∈ V (G).
// (+3 for recurrence)
// • Recurrence Relation:
// LP (v) = max{LP (v), 1 + max
// u∈ch(v){LP (u)}}
// Base case : LP (u) = 0; ∀u ∈ V : ch(u) = {φ}
// (+2 for this section)
// • Subproblem that solves the actual problem:
// For a given cell (i, j); LP (vi,j ) gives the actual solution.
// (+3 for algorithm)
// • Description of the algorithm:
// (a) Create a graph as discussed above.
// (b) For a given cell (i, j), return LP (vi,j )
// LP(v)
// (a) If ch(v) = {φ}
// – return 0
// (b) len ← 0
// (c) For each u ∈ ch(v) then
// – len ← max(len, 1 + LP (u))
// (d) return len
// Note : The problem can be solved without using the concept id DAG. The DP can be defined over the
// matrix directly. However, the solution sketch remains the same and instead of children, one can use the
// concept of adjacent cells directly. Then the direction of movement needs to be clearly defined as there is
// no directed edge defined on the matrix directly.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a cell in the matrix
struct Cell {
    int row;
    int col;
};

// Function to check if a cell is within the matrix bounds
bool isValid(int row, int col, int m, int n) {
    return (row >= 0 && row < m && col >= 0 && col < n);
}

// Function to find the longest increasing path from a given cell
int longestPathFromCell(vector<vector<char>>& matrix, vector<vector<int>>& dp, int row, int col) {
    if (dp[row][col] != -1) return dp[row][col];

    int m = matrix.size();
    int n = matrix[0].size();

    // Define possible movements in 8 directions
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    // Initialize length to 1
    int length = 1;

    // Try all 8 directions
    for (int i = 0; i < 8; ++i) {
        int newRow = row + dx[i];
        int newCol = col + dy[i];

        // Check if new cell is valid and has increasing character
        if (isValid(newRow, newCol, m, n) && matrix[newRow][newCol] == matrix[row][col] + 1) {
            length = max(length, 1 + longestPathFromCell(matrix, dp, newRow, newCol));
        }
    }

    // Store the calculated length in DP table
    dp[row][col] = length;
    return length;
}

// Function to find the longest increasing path in the matrix
int longestIncreasingPath(vector<vector<char>>& matrix) {
    int m = matrix.size();
    if (m == 0) return 0;
    int n = matrix[0].size();

    // Initialize DP table with -1
    vector<vector<int>> dp(m, vector<int>(n, -1));

    int maxLength = 0;

    // Iterate through each cell to find the longest path starting from it
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dp[i][j] == -1) {
                maxLength = max(maxLength, longestPathFromCell(matrix, dp, i, j));
            }
        }
    }

    return maxLength;
}

int main() {
    // Example usage
    vector<vector<char>> matrix = {
        {'A', 'B', 'C', 'D'},
        {'B', 'C', 'D', 'E'},
        {'C', 'D', 'E', 'F'},
        {'G', 'H', 'I', 'J'}
    };

    cout << "Length of the longest path: " << longestIncreasingPath(matrix) << endl;

    return 0;
}
