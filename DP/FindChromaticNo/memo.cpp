#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int chromaticNumberMemoization(const vector<vector<int>>& graph, int vertex, unordered_set<int>& colors,
                                unordered_map<string, int>& memo) {
    for (int neighbor : graph[vertex]) {
        colors.erase(neighbor);
    }

    if (colors.empty()) {
        return 1;
    }

    string key = to_string(vertex) + "_" + to_string(colors.size());
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }

    int minColors = INT_MAX;
    for (int color : colors) {
        unordered_set<int> nextColors = colors;
        nextColors.erase(color);
        minColors = min(minColors, 1 + chromaticNumberMemoization(graph, vertex + 1, nextColors, memo));
    }

    memo[key] = minColors;
    return minColors;
}

int findChromaticNumberMemoization(const vector<vector<int>>& graph) {
    int n = graph.size();
    unordered_set<int> colors;
    for (int i = 0; i < n; ++i) {
        colors.insert(i);
    }

    unordered_map<string, int> memo;
    return chromaticNumberMemoization(graph, 0, colors, memo);
}

int main() {
    // Example usage
    vector<vector<int>> graph = {{1, 2}, {0, 2}, {0, 1, 3}, {2, 4}, {3}};
    int chromaticNumber = findChromaticNumberMemoization(graph);

    // Output the result
    cout << "Chromatic Number: " << chromaticNumber << endl;

    return 0;
}
