#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int chromaticNumberRecursive(const vector<vector<int>>& graph, int vertex, unordered_set<int>& colors) {
    for (int neighbor : graph[vertex]) {
        colors.erase(neighbor);  // Remove colors of adjacent vertices
    }

    if (colors.empty()) {
        return 1;  // If no color is available, return 1 (need a new color)
    }

    int minColors = INT_MAX;
    for (int color : colors) {
        unordered_set<int> nextColors = colors;
        nextColors.erase(color);
        minColors = min(minColors, 1 + chromaticNumberRecursive(graph, vertex + 1, nextColors));
    }

    return minColors;
}

int findChromaticNumberRecursive(const vector<vector<int>>& graph) {
    int n = graph.size();
    unordered_set<int> colors;
    for (int i = 0; i < n; ++i) {
        colors.insert(i);
    }

    return chromaticNumberRecursive(graph, 0, colors);
}

int main() {
    // Example usage
    vector<vector<int>> graph = {{1, 2}, {0, 2}, {0, 1, 3}, {2, 4}, {3}};
    int chromaticNumber = findChromaticNumberRecursive(graph);

    // Output the result
    cout << "Chromatic Number: " << chromaticNumber << endl;

    return 0;
}
