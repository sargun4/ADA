// 3. In a city the department of police made every street one way. Despite
// of complaints and confusion from people the mayor claims that it is
// possible to legally drive from one intersection to another. Design an
// algorithm to verify or refute the mayor’s claim.

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

bool canDrive(const vector<vector<int>>& graph, int start, int end) {
    int n = graph.size();
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == end) {
            return true; // Found a path
        }

        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }

    return false; // No path found
}

int main() {
    // Example usage
    vector<vector<int>> graph = {
        {1, 2},     // Intersection 0, one-way streets to intersections 1 and 2
        {3},        // Intersection 1, one-way street to intersection 3
        {4},        // Intersection 2, one-way street to intersection 4
        {0},        // Intersection 3, one-way street back to intersection 0
        {1}         // Intersection 4, one-way street back to intersection 1
    };

    bool canDriveFrom0To3 = canDrive(graph, 0, 3);

    if (canDriveFrom0To3) {
        cout << "It is possible to legally drive from intersection 0 to intersection 3." << endl;
    } else {
        cout << "It is not possible to legally drive from intersection 0 to intersection 3." << endl;
    }

    return 0;
}


// Start DFS or BFS from an intersection.
// Explore all possible paths following the direction of one-way streets.
// If you reach the destination intersection, return that it's possible.
// If all paths are exhausted and the destination is not reached, return that it's not possible.