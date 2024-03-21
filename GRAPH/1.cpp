// 1. Consider a directed graph G, where each edge is colored either red,
// white, or blue. A walk in G is called a French flag walk if its sequence
// of edge colors is red, white, blue, red, white, blue, and so on.
// Describe an algorithm to find all vertices in G that can be reached
// from a given vertex v through a French flag walk.
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

// Struct to represent a directed edge with color
struct Edge {
    int dest;
    char color;
};

vector<int> frenchFlagWalk(const vector<vector<Edge>>& graph, int start) {
    vector<int> reachable;
    queue<int> q;
    unordered_set<int> visited;
    
    q.push(start);
    visited.insert(start);
    char flagColor = 'r'; // Starting with red
    
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        reachable.push_back(current);
        
        // Iterate over all neighbors
        for (const auto& edge : graph[current]) {
            if (edge.color == flagColor) {
                int neighbor = edge.dest;
                if (visited.find(neighbor) == visited.end()) {
                    visited.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }
        
        // Update flag color
        if (flagColor == 'r') flagColor = 'w';
        else if (flagColor == 'w') flagColor = 'b';
        else flagColor = 'r';
    }
    
    return reachable;
}

int main() {
    // Example usage
    vector<vector<Edge>> graph = {
        {{1, 'r'}, {2, 'w'}},   // Vertex 0
        {{3, 'b'}},             // Vertex 1
        {{1, 'r'}, {3, 'w'}},   // Vertex 2
        {{0, 'b'}}              // Vertex 3
    };

    vector<int> reachableVertices = frenchFlagWalk(graph, 0);

    cout << "Vertices reachable via French flag walk from vertex 0:\n";
    for (int v : reachableVertices) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}


// Initialize an empty queue Q and an empty set visited.
// Enqueue the starting vertex v into Q.
// Initialize a variable flag_color to 'red'.
// While Q is not empty:
// a. Dequeue a vertex u from Q.
// b. Mark u as visited.
// c. Find all neighbors of u.
// d. For each neighbor w:
// i. Check the color of the edge (u, w).
// ii. If the color matches the expected color according to the French flag pattern (red, white, blue, red, ...), enqueue w into Q.
// iii. Update the expected color to the next in the sequence (white -> blue -> red -> ...).
// Return the set of visited vertices.