// 14. Describe and analyze an algorithm to determine the number of shortest paths from a source
// vertex s to a target vertex t in an arbitrary directed graph G with weighted edges. You may
// assume that all edge weights are positive and that all necessary arithmetic operations can
// be performed in O(1) time. [Hint: Compute shortest path dists from s to every other
// vertex. Throw away all edges that cannot be part of a shortest path from s to another
// // vertex. What’s left?]

// - Run Dijkstra's algorithm from the source vertex `s` to compute the shortest-path dists from `s` to every other vertex in 
// the graph `G`. Let `dist[v]` denote the shortest distance from `s` to vertex `v`.
  
// - After computing the shortest-path dists, initialize an array `count[V]` to store the number of shortest paths from `s`
//  to each vertex `v`, where `V` is the number of vertices in the graph. Initialize `count[s] = 1` and `count[v] = 0` for all other vertices `v`.
  
// - Traverse the vertices in increasing order of their shortest-path dists from `s`. For each vertex `v`, iterate over
//  all its incoming edges `(u,v)` such that `dist[u] + wt(u,v) = dist[v]`. Update `count[v]` by adding `count[u]` to it.
  
// - After processing all vertices, `count[t]` will contain the number of shortest paths from `s` to `t`.

#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

struct Edge {
    int src, dest, wt;
};

vector<int> dijkstra(vector<vector<Edge>>& graph, int s) {
    int V = graph.size();
    vector<int> dist(V, numeric_limits<int>::max());
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto& edge : graph[u]) {
            if (dist[u] + edge.wt < dist[edge.dest]) {
                dist[edge.dest] = dist[u] + edge.wt;
                pq.push({dist[edge.dest], edge.dest});
            }
        }
    }

    return dist;
}

int countShortestPaths(vector<vector<Edge>>& graph, int s, int t) {
    vector<int> dist = dijkstra(graph, s);
    int V = graph.size();
    vector<int> count(V, 0);
    count[s] = 1;

    for (int v = 0; v < V; ++v) {
        for (auto& edge : graph[v]) {
            if (dist[edge.src] + edge.wt == dist[edge.dest]) {
                count[edge.dest] += count[edge.src];
            }
        }
    }

    return count[t];
}

int main() {
    int V = 5; // Number of vertices
    vector<vector<Edge>> graph(V);

    // Add edges to the graph (directed)
    graph[0].push_back({0, 1, 1});
    graph[0].push_back({0, 2, 1});
    graph[1].push_back({1, 2, 1});
    graph[1].push_back({1, 3, 1});
    graph[2].push_back({2, 3, 1});
    graph[2].push_back({2, 4, 1});
    graph[3].push_back({3, 4, 1});

    int s = 0; // Source vertex
    int t = 4; // Target vertex

    int numPaths = countShortestPaths(graph, s, t);
    cout << "Number of shortest paths from " << s << " to " << t << ": " << numPaths << endl;

    return 0;
}
