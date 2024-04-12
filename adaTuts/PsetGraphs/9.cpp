// // 9. Describe and analyze an algorithm to find the second smallest spanning tree of a given
// // graph G, that is, the spanning tree of G with smallest total wt except for the minimum
// // spanning tree.
 
 
// Use Prim's algorithm to find the minimum spanning tree T of the given graph G.
// Initialize a variable  secondSmallestWt to infinity.
// Iterate over all edges e in G that are not part of T:
// a. Add edge e to T.
// b. Use a modified version of Prim's algorithm to find the wt of the resulting spanning tree.
// c. If the wt of the resulting spanning tree is less than secondSmallestWt, update secondSmallestWt to this wt.
// d. Remove edge e from T.
// The value of  secondSmallestWt after the iteration is the wt of the second smallest spanning tree.
// The time complexity of this algorithm is O(E⋅V 2), where V is the number of vertices and E is the number of edges in the graph.
// This is because for each edge not in the MST, we perform a modified version of Prim's algorithm, which has a time complexity of O(V 2),
//  to calculate the wt of the resulting spanning tree. We do this for each of the O(E) edges not in the MST.

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Function to find the minimum spanning tree using Prim's algorithm
int primMST(vector<vector<pair<int, int>>>& graph, vector<bool>& vis, int start) {
    int totalWt = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap

    vis[start] = true;
    for (auto& edge : graph[start]) {
        pq.push({edge.second, edge.first});
    } 
    while (!pq.empty()) {
        auto [wt, u] = pq.top();
        pq.pop();

        if (vis[u]) continue;

        vis[u] = true;
        totalWt += wt;

        for (auto& edge : graph[u]) {
            if (!vis[edge.first]) {
                pq.push({edge.second, edge.first});
            }
        }
    }

    return totalWt;
}

// Function to find the second smallest spanning tree
int secondSmallestSpanningTree(vector<vector<pair<int, int>>>& graph) {
    int V = graph.size();
    int smallestWeight = INT_MAX;
    int secondSmallestWt = INT_MAX - 1; // Initialize to INT_MAX-1

    // Find the minimum spanning tree
    vector<bool> vis(V, false);
    smallestWeight = primMST(graph, vis, 0);

    // Iterate over all edges not in the MST and calculate the wt of resulting spanning trees
    for (int u = 0; u < V; ++u) {
        for (auto& edge : graph[u]) {
            int v = edge.first;
            int wt = edge.second;
            if (!vis[v]) {
                vector<bool> tempVis(V, false); // Temporary vis array for each iteration
                tempVis[u] = true;
                tempVis[v] = true;
                wt += primMST(graph, tempVis, u);
                if (wt > smallestWeight && wt < secondSmallestWt) {
                    secondSmallestWt = wt;
                }
            }
        }
    }

    return secondSmallestWt;
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

    int secondSmallest = secondSmallestSpanningTree(graph);
    if (secondSmallest == INT_MAX - 1) {
        cout << "No second smallest spanning tree exists.\n";
    } else {
        cout << "Weight of the second smallest spanning tree: " << secondSmallest << endl;
    }

    return 0;
}
