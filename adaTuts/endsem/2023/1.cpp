// 12 Marks) Given an m × n binary matrix whose 0 represents water and 1 represents land. The connected
// 1s form an island. Formally, a cell containing 1 with indices (i, j) (i indicates row and j indicates column) is
// considered connected to either of the following cells if that cell contains 1: (i − 1, j), (i − 1, j − 1), (i, j − 1),
// (i, j + 1), (i + 1, j), (i − 1, j + 1), (i + 1, j − 1), and (i + 1, j + 1). The below figure depicts a problem instance.
// Here the light-colored cells have 1s, and dark-colored cells have 0s. There are a total of 5 islands as indicated
// by digits 1 - 5. Design an O(mn)-time algorithm to count the number of islands.
// Graph construction:
// (+2 for identifying the problem is to find connected component) : The solution is inspired by finding the total
// number of connected components in a graph problem. The idea is to start Breadth–first search (BFS) from
// each unprocessed node and increment the island count. Each BFS traversal will mark all cells which make one
// island as processed. So, the problem reduces to finding the total number of BFS calls.\

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Define directions for movement (8 possible directions including diagonals)
const vector<pair<int, int>> directions = {
    {-1, 0}, {1, 0}, {0, -1}, {0, 1},   // Up, Down, Left, Right
    {-1, -1}, {-1, 1}, {1, -1}, {1, 1}  // Diagonal directions
};

// Function to perform BFS and mark all connected cells of an island as visited
void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col) {
    int m = grid.size();
    int n = grid[0].size();
    
    queue<pair<int, int>> q;
    q.push({row, col});
    visited[row][col] = true;
    
    while (!q.empty()) {
        int cur_row = q.front().first;
        int cur_col = q.front().second;
        q.pop();
        
        // Explore all 8 possible directions
        for (auto& dir : directions) {
            int new_row = cur_row + dir.first;
            int new_col = cur_col + dir.second;
            
            // Check if the new position is within bounds and contains '1' and is not visited
            if (new_row >= 0 && new_row < m && new_col >= 0 && new_col < n &&
                grid[new_row][new_col] == '1' && !visited[new_row][new_col]) {
                // Mark as visited and enqueue for further exploration
                visited[new_row][new_col] = true;
                q.push({new_row, new_col});
            }
        }
    }
}

// Function to count the number of islands in the binary matrix
int countIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int islandCount = 0;
    
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    
    // Iterate through each cell in the matrix
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] == '1' && !visited[i][j]) {
                // Found a new island, increment island count and perform BFS to mark all connected cells
                islandCount++;
                bfs(grid, visited, i, j);
            }
        }
    }
    
    return islandCount;
}

int main() {
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    
    int islands = countIslands(grid);
    
    cout << "Number of islands: " << islands << endl;
    
    return 0;
}
