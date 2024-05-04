// // User
// // 2. Suppose you are given an n × n square grid with squares being colored black or
// // white. Your input is a 2D array Gridn×n such that Grid(x, y) is either BLACK or
// // WHITE. Describe and analyze an algorithm that determines whether tokens can be
// // placed on the white squares of the grid so that
// // • every token is on a white square.
// // • every row of the grid contains exactly one token, and
// // • every column of the grid contains exactly one token.
// // Your output is single boolean.

// Algorithm Explanation:
// Modeling the Problem:
// Treat the problem as a bipartite graph where one set of nodes represents rows and the other set represents columns.
// Connect a row node to a column node if the corresponding cell in the grid is white (i.e., a valid position to place a token).
// Checking for Perfect Matching:
// Use an algorithm to determine if a perfect matching exists in this bipartite graph. A perfect matching means every node in one set (rows) is connected to exactly one node in the other set (columns), with no unconnected nodes.
// Steps:
// Build Bipartite Graph:
// Construct a bipartite graph based on the 
// 𝑛
// ×
// 𝑛
// n×n grid:
// Let 
// 𝑈
// U represent the set of row nodes (indexed by row number).
// Let 
// 𝑉
// V represent the set of column nodes (indexed by column number).
// For each white cell 
// 𝐺
// 𝑟
// 𝑖
// 𝑑
// [
// 𝑖
// ]
// [
// 𝑗
// ]
// =
// WHITE
// Grid[i][j]=WHITE, create an edge between node 
// 𝑖
// i (in 
// 𝑈
// U) and node 
// 𝑗
// j (in 
// 𝑉
// V).
// Check for Perfect Matching:
// Use an algorithm like Hopcroft–Karp or similar to find if there exists a perfect matching in this bipartite graph:
// Start by initializing the matching as empty.
// Use BFS or DFS to find augmenting paths in the bipartite graph and update the matching until no more augmenting paths can be found.
// If the size of the matching equals 
// 𝑛
// n, then a perfect matching exists, and the answer is true; otherwise, false.



#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_N = 100; // Maximum grid size

bool canPlaceTokens(vector<vector<int>>& grid, int n) {
    // Bipartite graph adjacency list
    vector<vector<int>> adj(n);
    
    // Build bipartite graph
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == 1) { // If cell is white
                adj[i].push_back(j);
            }
        }
    }
    
    // Matching array
    vector<int> match(n, -1);
    
    // Function to check if an augmenting path exists using DFS
    bool dfs(int u, vector<vector<int>>& adj, vector<int>& match, vector<bool>& visited) {
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                if (match[v] == -1 || dfs(match[v], adj, match, visited)) {
                    match[v] = u;
                    return true;
                }
            }
        }
        return false;
    }
    
    // Try to find a perfect matching using DFS
    int matching = 0;
    for (int i = 0; i < n; ++i) {
        vector<bool> visited(n, false);
        if (dfs(i, adj, match, visited)) {
            matching++;
        }
    }
    
    // Check if a perfect matching was found
    return (matching == n);
}

int main() {
    int n; // Size of the grid
    vector<vector<int>> grid(MAX_N, vector<int>(MAX_N));

    // Input example: grid filled with 0 (BLACK) and 1 (WHITE)
    // Fill the grid here...

    // Determine if tokens can be placed on white squares
    bool canPlace = canPlaceTokens(grid, n);

    cout << (canPlace ? "TRUE" : "FALSE") << endl;

    return 0;
}

// Graph Construction: Constructing the bipartite graph takes 
// 𝑂
// (
// 𝑛
// 2
// )
// O(n 
// 2
//  ) time.
// Hopcroft–Karp Algorithm (or similar): Finding a perfect matching using DFS or BFS in a bipartite graph has a time complexity of 
// 𝑂
// (
// 𝐸
// 𝑉
// )
// O(E 
// V
// ​
//  ), where 
// 𝑉
// =
// 𝑛
// V=n (number of row nodes) and 
// 𝐸
// E is the number of edges (edges between rows and columns, i.e., number of white cells).
// Overall, the time complexity of the algorithm is dominated by the graph traversal and matching algorithm, which is efficient for typical values of 
// 𝑛
// n.