// 10. Describe and analyze an efficient algorithm to compute, given a weighted undirected
// graph G and an integer k, the k spanning trees of G with smallest weight.
// 11. Suppose we are given a directed graph G with weighted edges and two vertices s and t.
// a) Describe and analyze an algorithm to find the shortest path from s to t when exactly
// one edge in G has negative weight. [Hint: Modify Dijkstra’s algorithm. Or don’t.]
// b) Describe and analyze an algorithm to find the shortest path from s to t when exactly
// k edges in G have negative weight. How does the running time of your algorithm
// depend on k?

//  algo
// Initialize an array 
// dist[V] to store the shortest distances from 
// s to all other vertices. Initialize all distances to infinity except for 
// =
// 0
// dist[s]=0.
// Initialize a priority queue 
// pq
// pq to store vertices ordered by their tentative distances from 
// s.
// Enqueue vertex 
// s with distance 
// 0
// 0 into 
// pq
// pq.
// While 
// pq
// pq is not empty:
// a. Dequeue the vertex 
// u with the smallest distance from 
// s from 
// pq
// pq.
// b. Relax all outgoing edges from 
// u by updating the distance to each neighbor vertex 
// v:
// If 

// dist[u]+weight(u,v)<dist[v], update 
// dist[v] to dist[u]+weight(u,v).
// Enqueue vertex 
// v with updated distance into 
// pq
// pq.
// The shortest path from 
// s to 
// t is 
// dist[t].
// The time complexity of this algorithm is  O((V+E)logV), where 
// V is the number of vertices and 
// E is the number of edges in the graph.

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// Data structure to represent an edge
struct Edge {
    int u, v, weight;
};

// Function to find the k smallest spanning trees of the graph
vector<vector<Edge>> kSmallestSpanningTrees(vector<vector<Edge>>& graph, int k) {
    // Prim's algorithm to find the minimum spanning tree
    auto primMST = [](vector<vector<Edge>>& g) -> vector<Edge> {
        vector<Edge> MST;
        int V = g.size();
        vector<bool> visited(V, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        visited[0] = true;
        for (Edge& edge : g[0]) {
            pq.push({edge.weight, edge.v});
        }

        while (!pq.empty()) {
            auto [weight, u] = pq.top();
            pq.pop();

            if (visited[u]) continue;

            visited[u] = true;
            MST.push_back({0, u, weight});

            for (Edge& edge : g[u]) {
                if (!visited[edge.v]) {
                    pq.push({edge.weight, edge.v});
                }
            }
        }

        return MST;
    };

    vector<vector<Edge>> kSpanningTrees;
    kSpanningTrees.push_back(primMST(graph));

    for (int i = 1; i < k; ++i) {
        vector<vector<Edge>> newGraph(graph);

        // Remove edges present in previous MSTs
        for (Edge& edge : kSpanningTrees.back()) {
            newGraph[edge.u].erase(remove_if(newGraph[edge.u].begin(), newGraph[edge.u].end(),
                                              [&](Edge& e) { return e.v == edge.v; }),
                                   newGraph[edge.u].end());
            newGraph[edge.v].erase(remove_if(newGraph[edge.v].begin(), newGraph[edge.v].end(),
                                              [&](Edge& e) { return e.v == edge.u; }),
                                   newGraph[edge.v].end());
        }

        // Find the next MST
        kSpanningTrees.push_back(primMST(newGraph));
    }

    return kSpanningTrees;
}

// Function to find the shortest path from s to t when exactly one edge in G has negative weight
int shortestPathWithOneNegativeEdge(vector<vector<Edge>>& graph, int s, int t) {
    int V = graph.size();
    vector<int> dist(V, inf);
    dist[s] = 0;

    for (int i = 0; i < V - 1; ++i) {
        for (int u = 0; u < V; ++u) {
            for (Edge& edge : graph[u]) {
                if (dist[u] != inf && dist[u] + edge.weight < dist[edge.v]) {
                    dist[edge.v] = dist[u] + edge.weight;
                }
            }
        }
    }

    return dist[t];
}

// Function to find the shortest path from s to t when exactly k edges in G have negative weight
int shortestPathWithKNegativeEdges(vector<vector<Edge>>& graph, int s, int t, int k) {
    int V = graph.size();
    vector<int> dist(V, inf);
    dist[s] = 0;

    for (int i = 0; i < k; ++i) {
        for (int u = 0; u < V; ++u) {
            for (Edge& edge : graph[u]) {
                if (dist[u] != inf && dist[u] + edge.weight < dist[edge.v]) {
                    dist[edge.v] = dist[u] + edge.weight;
                }
            }
        }
    }

    // Check for negative cycles
    for (int u = 0; u < V; ++u) {
        for (Edge& edge : graph[u]) {
            if (dist[u] != inf && dist[u] + edge.weight < dist[edge.v]) {
                // Negative cycle found
                return inf;
            }
        }
    }

    return dist[t];
}

int main() {
    // Example usage for k smallest spanning trees
    vector<vector<Edge>> graph = {
        {{1, 2, 1}, {0, 3, 3}},
        {{0, 2, 2}, {1, 3, 2}},
        {{0, 1, 1}, {2, 3, 1}},
        {{0, 1, 3}, {1, 2, 2}, {2, 3, 1}}
    };
    int k = 2;
    vector<vector<Edge>> kTrees = kSmallestSpanningTrees(graph, k);

    cout << "K smallest spanning trees:\n";
    for (int i = 0; i < k; ++i) {
        cout << "Tree " << i + 1 << ":\n";
        for (Edge& edge : kTrees[i]) {
            cout << edge.u << " - " << edge.v << " : " << edge.weight << endl;
        }
    }

    // Example usage for shortest path with one negative edge
    int s = 0, t = 3;
    int shortestOneNegative = shortestPathWithOneNegativeEdge(graph, s, t);
    cout << "Shortest path with one negative edge from " << s << " to " << t << ": " << shortestOneNegative << endl;

    // Example usage for shortest path with k negative edges
    int kNegEdges = 2;
    int shortestKNegative = shortestPathWithKNegativeEdges(graph, s, t, kNegEdges);
    cout << "Shortest path with " << kNegEdges << " negative edges from " << s << " to " << t << ": " << shortestKNegative << endl;

    return 0;
}
