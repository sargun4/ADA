// To find every (s, t)-cut vertex in a directed acyclic graph (DAG) 
// G with a unique source 
// s and a unique sink 
// t, we can use a variation of depth-first search (DFS) algorithm.

// The idea is to perform a DFS traversal starting from the source vertex 
// s and mark vertices that are reachable from 
// s. Then, perform another DFS traversal starting from the sink vertex 
// t and mark vertices that can reach 
// t. Finally, the vertices that were not marked in both traversals are the (s, t)-cut vertices.

// Here's the algorithm:

// Perform a DFS traversal starting from the source vertex 
// s, marking all reachable vertices.
// Perform a DFS traversal starting from the sink vertex 
// t, marking all vertices that can reach 
// t.
// The vertices that were not marked in both traversals are the (s, t)-cut vertices.

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Data structure to represent a directed acyclic graph (DAG)
class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    Graph(int V) : V(V), adj(V) {}

    // Add an edge to the graph
    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    // Perform a depth-first search (DFS) traversal
    void dfs(int v, vector<bool>& vis) {
        vis[v] = true;
        for (int u : adj[v]) {
            if (!vis[u]) {
                dfs(u, vis);
            }
        }
    }

    // Find every (s, t)-cut vertex in the graph
    vector<int> findSTCutVertices(int source, int sink) {
        vector<bool> reachableFromSource(V, false); // Mark vertices reachable from the source
        vector<bool> canReachSink(V, false); // Mark vertices that can reach the sink

        // Step 1: Perform DFS traversal starting from the source vertex
        dfs(source, reachableFromSource);

        // Step 2: Perform DFS traversal starting from the sink vertex
        dfs(sink, canReachSink);

        // Step 3: Find (s, t)-cut vertices
        vector<int> cutVertices;
        for (int v = 0; v < V; ++v) {
            if (v != source && v != sink && !reachableFromSource[v] && canReachSink[v]) {
                cutVertices.push_back(v);
            }
        }
        return cutVertices;
    }
};

int main() {
    // Example usage
    Graph G(7); // Creating a graph with 7 vertices

    // Adding edges to the graph
    G.addEdge(0, 1);
    G.addEdge(0, 2);
    G.addEdge(1, 3);
    G.addEdge(2, 3);
    G.addEdge(3, 4);
    G.addEdge(3, 5);
    G.addEdge(4, 6);
    G.addEdge(5, 6);

    int source = 0; // Source vertex
    int sink = 6;   // Sink vertex

    vector<int> cutVertices = G.findSTCutVertices(source, sink);

    cout << "The (s, t)-cut vertices in the graph are: ";
    for (int vertex : cutVertices) {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}

// performs two DFS traversals to mark vertices that are reachable from the source and vertices that can reach the sink. Finally, it
//  identifies the vertices that were not marked in both traversals as the (s, t)-cut vertices. The time complexity of the algorithm is 
 
// O(V+E), where 
// V is the number of vertices and 
// E is the number of edges in the graph.