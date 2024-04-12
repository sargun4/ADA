// 12. For any edge e in any graph G, let G \ e denote the graph obtained by deleting e from G.
// Suppose we are given a graph G and two vertices s and t. The replacement paths problem
// asks us to compute the shortest-path distance from s to t in G \ e, for every edge e of G.
// The output is an array of E distances, one for each edge of G.

// a) Suppose G is a directed graph, and the shortest path from vertex s to vertex t passes
// through every vertex of G. Describe an algorithm to solve this special case of the replacement paths problem in O(E log V) time.

// b) Describe an algorithm to solve the replacement paths problem for arbitrary undirected
// graphs in O(E log V) time.
// In both subproblems, you may assume that all edge weights are non-negative. [Hint: If
// we delete an edge of the original shortest path, how do the old and new shortest paths overlap?]
 
 
// a) To solve the special case of the replacement paths problem in a directed graph where the shortest path from vertex 
// s to vertex t passes through every vertex of G, we can use Dijkstra's algorithm with a slight modification.
// 1. Run Dijkstra's algorithm from vertex s to find the shortest paths from 
// s to all other vertices in 
// G. Let 
// dist_s[v] represent the shortest distance from 
// s to vertex 
// v in 
// G.
// 2. Run Dijkstra's algorithm from vertex 
// t to find the shortest paths from all other vertices to 
// t in 
// G. Let 
// dist_t[v] represent the shortest distance from vertex 
// v to 
// t in 
// G.
// 3. For each edge 
// (e(u,v)) in 
// G, the shortest path distance from 
// s to 
// t passing through 
// e is 
// dist_s[u] + dist_t[v] + wt(e).
   
//    This approach runs Dijkstra's algorithm twice, once from 
//    s and once from 
//    t, which takes 
//    O(ElogV) time for each run. Therefore, the overall time complexity of the algorithm is 
//    O(ElogV).

// b) For arbitrary undirected graphs, we can solve the replacement paths problem using a similar approach:
// 1. Run Dijkstra's algorithm from vertex 
// s to find the shortest paths from 
// s to all other vertices in 
// G. Let 
// dist_s[v] represent the shortest distance from 
// s to vertex 
// v in 
// G.
// 2. For each edge 
// (e(u,v)) in 
// G, temporarily remove the edge 
// e from the graph.
// 3. Run Dijkstra's algorithm from vertex 
// t to find the shortest paths from all other vertices to 
// t in the modified graph 
// G\e. Let 
// dist_t[v] represent the shortest distance from vertex 
// v to 
// t in 
// G\e.
// 4. Restore the edge 
// e in the graph 
// G.
// 5. For each edge 
// (e(u,v)) in 
// G, the shortest path distance from 
// s to 
// t passing through 
// e is 
// dist_s[u] + dist_t[v] + wt(e).
   
//    This approach also takes 
//    O(ElogV) time because we run Dijkstra's algorithm twice, once from 
//    s and once from 
//    t, with a temporary modification of the graph. Therefore, the overall time complexity of the algorithm remains 
//    O(ElogV).


 #include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// Function to find the shortest paths from source vertex s using Dijkstra's algorithm
vector<int> dijkstra(vector<vector<pair<int, int>>>& graph, int s) {
    int V = graph.size();
    vector<int> dist(V, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;//minheap {node,dist}
    dist[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (d > dist[u]) continue;
        for (auto& [v, wt] : graph[u]) {
            if (dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

// Function to solve replacement paths problem for directed graph in O(E log V) time
vector<int> replacementPathsDirected(vector<vector<pair<int, int>>>& graph, int s, int t) {
    vector<int> dist_s = dijkstra(graph, s);
    vector<int> dist_t = dijkstra(graph, t);
    int V = graph.size();
    vector<int> res(V, INT_MAX);

    for (int u = 0; u < V; ++u) {
        for (auto& [v, wt] : graph[u]) {
            res[u] = min(res[u], dist_s[u] + dist_t[v] + wt);
        }
    }

    return res;
}

// Function to solve replacement paths problem for undirected graph in O(E log V) time
vector<int> replacementPathsUndirected(vector<vector<pair<int, int>>>& graph, int s, int t) {
    int V = graph.size();
    vector<int> res(V, INT_MAX);

    for (int u = 0; u < V; ++u) {
        for (auto& [v, wt] : graph[u]) {
            // Temporarily remove the edge (u, v) from the graph
            vector<pair<int, int>> temp_graph = graph[u];
            for (auto& [adj_v, adj_weight] : temp_graph) {
                if (adj_v == v) {
                    adj_weight = INT_MAX; // Set wt to infinity
                    break;
                }
            }

            // Run Dijkstra's algorithm from t
            vector<int> dist_t = dijkstra(temp_graph, t);

            // Restore the edge (u, v)
            for (auto& [adj_v, adj_weight] : temp_graph) {
                if (adj_v == v) {
                    adj_weight = wt;
                    break;
                }
            }

            // Update the res
            res[u] = min(res[u], dist_t[u] + wt);
        }
    }

    return res;
}

int main() {
    // Example usage for directed graph
    int V = 4; // Number of vertices
    vector<vector<pair<int, int>>> directedGraph(V);

    // Add edges to the directed graph
    directedGraph[0].push_back({1, 2});
    directedGraph[0].push_back({2, 5});
    directedGraph[1].push_back({2, 1});
    directedGraph[1].push_back({3, 7});
    directedGraph[2].push_back({3, 3});

    int s = 0; // Source vertex
    int t = 3; // Destination vertex

    vector<int> resultDirected = replacementPathsDirected(directedGraph, s, t);
    cout << "Replacement Paths for Directed Graph:" << endl;
    for (int i = 0; i < V; ++i) {
        cout << "Distance from " << s << " to " << t << " through vertex " << i << ": " << resultDirected[i] << endl;
    }
    cout << endl;

    // Example usage for undirected graph
    vector<vector<pair<int, int>>> undirectedGraph(V);

    // Add edges to the undirected graph
    undirectedGraph[0].push_back({1, 2});
    undirectedGraph[0].push_back({2, 5});
    undirectedGraph[1].push_back({2, 1});
    undirectedGraph[1].push_back({3, 7});
    undirectedGraph[2].push_back({3, 3});

    vector<int> resultUndirected = replacementPathsUndirected(undirectedGraph, s, t);
    cout << "Replacement Paths for Undirected Graph:" << endl;
    for (int i = 0; i < V; ++i) {
        cout << "Distance from " << s << " to " << t << " through vertex " << i << ": " << resultUndirected[i] << endl;
    }

    return 0;
}
