// 4. Given a directed graph G, design an algorithm to compute number of
// 2k length cycle for 2 < k < n/2.
 
// Below is a simplified example using Floyd-Warshall algorithm to compute all-pairs shortest paths.
 

#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

int count2kCycles(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<int>> dist(n, vector<int>(n, INF));

    // Initialize distances with direct edges
    for (int i = 0; i < n; ++i) {
        for (int j : graph[i]) {
            dist[i][j] = 1;
        }
    }

    // Floyd-Warshall algorithm for all-pairs shortest paths
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Count number of 2k length cycles
    int count = 0;
    for (int k = 1; k < n / 2; ++k) {
        for (int i = 0; i < n; ++i) {
            if (dist[i][i] == 2 * k) {
                count++;
            }
        }
    }

    return count;
} 
int main() {
    // Example usage
    vector<vector<int>> graph = {
        {1},    // Vertex 0 is connected to vertex 1
        {2},    // Vertex 1 is connected to vertex 2
        {0}     // Vertex 2 is connected to vertex 0
    };

    int num2kCycles = count2kCycles(graph);
    cout << "Number of 2k length cycles for 2 < k < n/2: " << num2kCycles << endl;

    return 0;
}



// Compute the all-pairs shortest paths matrix using Floyd-Warshall or Johnson's algorithm.
// For each vertex v, iterate over all other vertices w and check if there exists a path from v to w with exactly 2k edges for 2 < k < n/2.
// Count the number of such paths found.