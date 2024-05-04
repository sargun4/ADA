// 1. Suppose you are given an n × n checkerboard with some of the squares deleted. You

// have a large set of dominos, just the right size to cover two squares of the checker-
// board. Describe and analyze an algorithm to determine whether one tile the board

// with dominos – each domino must cover exactly two undeleted squares, and each
// undeleted square must be covered by exactly one domino.
// Your input is a 2D boolean array DELETEDn×n where DELETED(x, y) is TRUE if
// and only if the square in row X and column y has been deleted. Your output is a
// single boolean; you do not have to compute the actual placement of dominos. In the
// example board shown in Figure 1 - your algorithm should return TRUE.

// Figure 1: Covering a partial checkerboard with dominoes

// Algorithm Explanation:
// Modeling the Problem as a Graph:
// Represent the checkerboard as a graph where each cell corresponds to a node.
// For each node (corresponding to an undeleted square), connect it to adjacent nodes (corresponding to neighboring undeleted squares) if they exist.
// Checking for Bipartiteness:
// Use graph theory concepts to determine if the graph is bipartite.
// A bipartite graph is one where the nodes can be colored with two colors such that no two adjacent nodes share the same color.
// In our context, if a graph is bipartite, it means we can tile the checkerboard with dominos.
// Steps:
// Graph Construction:
// Create a graph representation of the checkerboard using adjacency lists.
// Traverse through the checkerboard cells, and for each undeleted cell, add edges to its neighboring undeleted cells.
// Graph Coloring (Bipartiteness Check):
// Use a Depth-First Search (DFS) or Breadth-First Search (BFS) algorithm to check if the graph is bipartite.
// During traversal, assign colors (say 0 and 1) alternately to neighboring nodes.
// If at any point during the traversal, you encounter a situation where adjacent nodes have the same color, then the graph is not bipartite.


#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    bool canTileWithDominos(vector<vector<bool>>& deleted) {
        int n = deleted.size();
        if (n == 0) return true; // Edge case for empty board

        // Count total undeleted squares
        int totalUndeleted = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!deleted[i][j]) {
                    totalUndeleted++;
                }
            }
        }

        // If total undeleted squares is odd, cannot tile with dominos
        if (totalUndeleted % 2 != 0) {
            return false;
        }

        // Create a bipartite graph representation for maximum bipartite matching
        vector<vector<int>> adj(n * n); // Adjacency list for the graph
        vector<int> match(n * n, -1);   // Match array for storing matching info

        // Connect each undeleted square to its potential neighboring squares
        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (!deleted[i][j]) {
                    int node1 = i * n + j;
                    for (int k = 0; k < 4; ++k) {
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n && !deleted[ni][nj]) {
                            int node2 = ni * n + nj;
                            adj[node1].push_back(node2);
                        }
                    }
                }
            }
        }

        // Implement maximum bipartite matching using DFS
        for (int u = 0; u < n * n; ++u) {
            vector<bool> visited(n * n, false);
            if (dfs(u, adj, visited, match)) {
                totalUndeleted -= 2; // Each matching covers two squares
            }
        }

        // If all undeleted squares can be matched, return true
        return totalUndeleted == 0;
    }

private:
    bool dfs(int u, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& match) {
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                if (match[v] == -1 || dfs(match[v], adj, visited, match)) {
                    match[v] = u;
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    // Example usage:
    vector<vector<bool>> deleted = {
        {false, true, false},
        {true, false, true},
        {false, true, false}
    };

    Solution sol;
    bool canTile = sol.canTileWithDominos(deleted);

    if (canTile) {
        cout << "The board can be tiled with dominos." << endl;
    } else {
        cout << "The board cannot be tiled with dominos." << endl;
    }

    return 0;
}
