#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int findChromaticNumberTabulation(const vector<vector<int>>& graph) {
    int n = graph.size();
    int maxColors = n;

    // dp[i][j] represents the minimum number of colors needed for subgraph starting from vertex i with j colors
    vector<vector<int>> dp(n + 1, vector<int>(maxColors + 1, INT_MAX));

    // Base case: no colors needed for subgraph with 0 colors
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 0;
    }

    for (int i = n - 1; i >= 0; --i) {
        for (int colors = 1; colors <= maxColors; ++colors) {
            unordered_set<int> usedColors;
            for (int neighbor : graph[i]) {
                usedColors.insert(dp[neighbor][colors - 1]);
            }

            for (int color : usedColors) {
                dp[i][colors] = min(dp[i][colors], max(1, color));
            }
        }
    }

    int result = INT_MAX;
    for (int colors = 1; colors <= maxColors; ++colors) {
        result = min(result, dp[0][colors]);
    }

    return result;
}

int main() {
    // Example usage
    vector<vector<int>> graph = {{1, 2}, {0, 2}, {0, 1, 3}, {2, 4}, {3}};
    int chromaticNumber = findChromaticNumberTabulation(graph);

    // Output the result
    cout << "Chromatic Number: " << chromaticNumber << endl;

    return 0;
}
