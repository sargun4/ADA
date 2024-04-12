// 13. Suppose you are given a directed graph G in which every edge has negative weight, and

// a source vertex s. Describe and analyze an efficient algorithm that computes the shortest-
// path distances from s to every other vertex in G. Specifically, for every vertex t:

// • If t is not reachable from s, your algorithm should report dist(t) = ∞.
// • If G has a cycle that is reachable from s, and t is reachable from that cycle, then the
// shortest-path distance from s to t is not well-defined, because there are paths (formally,
// walks) from s to t of arbitrarily large negative length. In this case, your algorithm
// should report dist(t) = -∞.
// • If neither of the two previous conditions applies, your algorithm should report the
// correct shortest-path distance from s to t.


// algo-

// - Initialize an array `dist[V]` to store the shortest-path distances from `s` to every other vertex `t` in the graph, where `V` is the
//  number of vertices in the graph. Initialize `dist[s] = 0` and `dist[v] = ∞` for all other vertices `v`.
// - Relax all edges \( |V| - 1 \) times. In each iteration, update the distance of each vertex `v` if there exists an edge 
// \( (u,v) \) such that `dist[u] + weight(u,v) < dist[v]`.
// - After \( |V| - 1 \) iterations, if there are any vertices `v` such that `dist[u] + weight(u,v) < dist[v]`, then there
//  exists a negative cycle reachable from the source vertex `s`.
// - If a negative cycle is reachable from `s`, update the distance of all vertices reachable from this cycle to `-∞`.
// - Otherwise, `dist[v]` holds the shortest-path distance from `s` to `v`.
 
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Edge {
    int src, dest, weight;
};

void bellmanFord(const vector<Edge>& edges, int V, int src) {
    vector<int> dist(V, numeric_limits<int>::max());
    dist[src] = 0;

    for (int i = 0; i < V - 1; ++i) {
        for (const Edge& edge : edges) {
            if (dist[edge.src] != numeric_limits<int>::max() && dist[edge.src] + edge.weight < dist[edge.dest]) {
                dist[edge.dest] = dist[edge.src] + edge.weight;
            }
        }
    }

    // Check for negative cycles
    for (const Edge& edge : edges) {
        if (dist[edge.src] != numeric_limits<int>::max() && dist[edge.src] + edge.weight < dist[edge.dest]) {
            cout << "Graph contains a negative cycle reachable from source vertex " << src << endl;
            return;
        }
    }

    // Output shortest-path distances
    for (int i = 0; i < V; ++i) {
        if (dist[i] == numeric_limits<int>::max()) {
            cout << "dist(" << src << ", " << i << ") = ∞" << endl;
        } else if (dist[i] == numeric_limits<int>::min()) {
            cout << "dist(" << src << ", " << i << ") = -∞" << endl;
        } else {
            cout << "dist(" << src << ", " << i << ") = " << dist[i] << endl;
        }
    }
}

int main() {
    vector<Edge> edges = {{0, 1, 6}, {0, 2, 7}, {1, 2, 8}, {1, 3, 5}, {2, 3, -3}, {3, 4, 9}, {4, 2, 7}};
    int V = 5; // Number of vertices
    int src = 0; // Source vertex

    bellmanFord(edges, V, src);

    return 0;
}
