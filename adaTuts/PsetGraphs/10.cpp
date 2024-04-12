// // 10. Describe and analyze an efficient algorithm to compute, given a weighted undirected
// // graph G and an integer k, the k spanning trees of G with smallest weight.

// 1.Initialize an empty vector of vectors, spanningTrees, to store the k spanning trees.
// 2.Initialize a priority queue to store the edges of the graph. Each element in the priority queue will be a pair (weight, edge) where edge is represented as a pair (u, v) denoting an edge between vertices u and v, and weight is the weight of that edge.
// 3.Initialize a counter count to keep track of the number of spanning trees found.
// 4.Push all edges of the graph onto the priority queue.
// 5.While the priority queue is not empty and we haven't found 
// k spanning trees:
//   - Pop the top element from the priority queue.
//   - Run Prim's algorithm starting from the vertex u of the popped edge to find the MST.
//   - If the MST is not empty and doesn't contain cycles:
//         - Add the MST to spanningTrees.
//         - Increment count.
// 6.Return spanningTrees.




#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

// Data structure to represent an edge
struct Edge {
    int u, v, weight;
};

// Comparator function to sort edges by weight
bool compareEdges(const Edge& e1, const Edge& e2) {
    return e1.weight < e2.weight;
}

// Function to find the minimum spanning tree using Prim's algorithm
vector<Edge> primMST(const vector<vector<pair<int, int>>>& graph, vector<bool>& visited, int start) {
    vector<Edge> mst;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap

    visited[start] = true;
    for (const auto& [v, weight] : graph[start]) {
        pq.push({weight, v});
    } 
    while (!pq.empty()) {
        auto [weight, u] = pq.top();
        pq.pop();

        if (visited[u]) continue;

        visited[u] = true;
        
        // Add the edge to the MST
        if (u != start) {
            mst.push_back({start, u, weight});
        }

        for (const auto& [v, w] : graph[u]) {
            if (!visited[v]) {
                pq.push({w, v});
            }
        }
    }

    return mst;
}

// Function to compute k spanning trees with smallest weight
vector<vector<Edge>> kSpanningTrees(const vector<vector<pair<int, int>>>& graph, int k) {
    vector<vector<Edge>> spanningTrees;
    int V = graph.size();

    // Push all edges onto the priority queue
    vector<Edge> edges;
    for (int u = 0; u < V; ++u) {
        for (const auto& [v, weight] : graph[u]) {
            if (u < v) {
                edges.push_back({u, v, weight});
            }
        }
    }
    sort(edges.begin(), edges.end(), compareEdges);

    // Initialize count of spanning trees found
    int count = 0;

    // Iterate over the sorted edges
    for (const auto& edge : edges) {
        if (count == k) {
            break;
        }

        // Check if adding the edge creates a cycle
        vector<bool> visited(V, false);
        visited[edge.u] = true;
        vector<Edge> mst = primMST(graph, visited, edge.v);

        // If the MST is not empty and doesn't contain cycles
        if (!mst.empty() && mst.size() == V - 1) {
            spanningTrees.push_back(mst);
            ++count;
        }
    }

    return spanningTrees;
}

int main() {
    // Example usage
    int V = 5; // Number of vertices
    vector<vector<pair<int, int>>> graph(V);

    // Add edges to the graph (undirected)
    graph[0].push_back({1, 2});
    graph[0].push_back({2, 3});
    graph[1].push_back({2, 5});
    graph[1].push_back({3, 6});
    graph[2].push_back({3, 4});
    graph[2].push_back({4, 7});
    graph[3].push_back({4, 8});

    int k = 3; // Number of spanning trees to find

    vector<vector<Edge>> spanningTrees = kSpanningTrees(graph, k);

    // Output the k spanning trees
    for (int i = 0; i < k; ++i) {
        cout << "Spanning Tree " << i + 1 << ":" << endl;
        for (const auto& edge : spanningTrees[i]) {
            cout << "(" << edge.u << ", " << edge.v << ") Weight: " << edge.weight << endl;
        }
        cout << endl;
    }

    return 0;
}
