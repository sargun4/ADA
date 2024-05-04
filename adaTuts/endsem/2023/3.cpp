// q3. (12 Marks) There are n teams that plan to attend a grand dinner in a restaurant. Team i has ti members.
// The restaurant can provide m tables for the dinner, with m ≥ n. Table i can has si chairs. We wish to seat
// all the teams such that no two team members are at the same table, so that we maximum students getting to
// meet members of other teams. Can we do so?
// Model this as a network flow problem. Specify the vertices, edges and capacities. Then finally, explain how
// you can transform the maximum flow into an optimal solution to this problem.
// • Flow network construction (including vertices, edges, capacities):
// (+4 for proper construction of the graph. Any correct drawing of graph with little elaboration is also
// accepted) : Create a flow network with n + m + 2 vertices. Create one vertex for each team and one
// for each table. Create extra source and sink vertices. Create edges from the source to each team with a
// capacity of ti. Create edges from each table vertex to the sink vertex with capacity si. Finally, add edges
// from each team to each table, with capacity 1, since each team can provide at most one person per table.
// • How does the maximum-flow of your network can be transformed into an optimal solution to this problem?
// (+3 for the point. 0 if not mentioned correctly) : Run the network flow algorithm. If the maximal flow
// equals the sum of the number of team members, the seating can be done. Otherwise, it can not be.
// • Algorithm Description:
// (+2 for this section)
// (a) Create the graph as explained above
// (b) Use the Ford Fulkerson’s algorithm to get the max-flow from s to t for the above graph.
// (c) If the max flow is equal to the sum of the team members, output TRUE, else output FALSE.
// (+3 for this section / +1 if it is not mentioned that the algorithms runs in polynomial time, i.e. the
// maximum flow is polynomial w.r.t input graph)
// • Explanation of the running time: The running time of the algorithm depends on the creation of the graph
// and the running time of Ford Fulkerson’s algorithm. Noticed the induced graph between teams and table
// can be a complete bipartite graph. So the edge complexity of the graph can be O(mn) in the worst case.
// The running time of Ford Fulkerson’s algorithm is O(|E| × f ) where |E| is the number of edges in the
// graph and f is the maximum flow. Now here, since the maximum flow here can be maximum O(mn), the
// total complexity of the graph is O(m2n2)
 
### Flow Network Construction:
1. **Vertices**:
   - Source vertex  s
   - Sink vertex  t
   - Vertices for each team  T_1, T_2, \ldots, T_n
   - Vertices for each table  Table_1, Table_2, \ldots, Table_m

2. **Edges and Capacities**:
   - **From Source to Team**:
     - Create edges from source  s to each team vertex  T_i with a capacity of  t_i (number of members in team  i).
   - **From Table to Sink**:
     - Create edges from each table vertex  Table_j to sink  t with a capacity of  s_j (number of chairs at table  j).
   - **Between Team and Table**:
     - Create edges from each team vertex  T_i to each table vertex  Table_j with a capacity of 1, indicating that each team member can occupy at most one chair at a table.

### Transforming Maximum Flow into Optimal Solution:
1. **Algorithm Description**:
   - **Graph Construction**:
     - Construct the flow network as described above.
   - **Ford-Fulkerson Algorithm**:
     - Use the Ford-Fulkerson algorithm (or any other maximum flow algorithm like Edmonds-Karp) to calculate the maximum flow from the source  s to the sink  t in the constructed flow network.
   - **Evaluation**:
     - After computing the maximum flow, if the total flow value equals the sum of all team members (i.e.,  \text{max\_flow} = \sum_{i=1}^n t_i), then it's possible to seat all team members such that no two members from different teams sit at the same table.
     - If the maximum flow does not equal the total number of team members, then it's not possible to seat all teams as required.

### Explanation of Running Time:
- **Graph Complexity**:
  - The graph can have  n + m + 2 vertices and potentially  n \times m edges (in the worst case where each team can potentially sit at each table).
- **Ford-Fulkerson Algorithm**:
  - The running time of the Ford-Fulkerson algorithm depends on the number of edges and the maximum flow value  f in the graph.
  - In the worst case, the number of edges could be  O(mn) (considering all possible connections between teams and tables).
  - Therefore, the total complexity of the algorithm can be  O(m^2n^2), considering the maximum flow could be as large as  O(mn).

This approach effectively models the seating problem as a maximum flow problem, allowing for an optimal solution to determine if all teams can be seated without any team members from different teams sharing the same table. The Ford-Fulkerson algorithm is suitable for this task given its polynomial time complexity concerning the size of the graph and the maximum flow.
```
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Ford-Fulkerson algorithm to find the maximum flow in a flow network
class FordFulkerson {
private:
    int n; // Number of vertices
    vector<vector<int>> capacity; // Capacity matrix
    vector<vector<int>> residualCapacity; // Residual capacity matrix
    vector<bool> visited; // Visited array to track visited nodes

    // Helper function: Perform BFS to find an augmenting path
    bool bfs(int source, int sink, vector<int>& parent) {
        fill(visited.begin(), visited.end(), false);
        queue<int> q;
        q.push(source);
        visited[source] = true;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v = 0; v < n; ++v) {
                if (!visited[v] && residualCapacity[u][v] > 0) {
                    parent[v] = u;
                    visited[v] = true;
                    q.push(v);
                    if (v == sink)
                        return true;
                }
            }
        }
        return false;
    }

    // Helper function: Use DFS to find the augmenting path and update residual capacities
    int dfs(int u, int sink, int minEdge, vector<int>& parent) {
        if (u == sink)
            return minEdge;

        int maxFlow = 0;
        for (int v = 0; v < n; ++v) {
            if (!visited[v] && residualCapacity[u][v] > 0) {
                visited[v] = true;
                parent[v] = u;
                int flow = dfs(v, sink, min(minEdge, residualCapacity[u][v]), parent);
                if (flow > 0) {
                    residualCapacity[u][v] -= flow;
                    residualCapacity[v][u] += flow;
                    return flow;
                }
            }
        }
        return 0;
    }

public:
    FordFulkerson(int numVertices) : n(numVertices) {
        capacity.resize(n, vector<int>(n, 0));
        residualCapacity.resize(n, vector<int>(n, 0));
        visited.resize(n, false);
    }

    void addEdge(int u, int v, int cap) {
        capacity[u][v] += cap; // Add capacity to the original graph
        residualCapacity[u][v] += cap; // Initialize residual capacity
    }

    int maxFlow(int source, int sink) {
        vector<int> parent(n, -1);
        int maxFlow = 0;

        // Augment the flow while there's an augmenting path from source to sink
        while (bfs(source, sink, parent)) {
            fill(visited.begin(), visited.end(), false);
            int pathFlow = dfs(source, sink, INT_MAX, parent);
            while (pathFlow > 0) {
                maxFlow += pathFlow;
                pathFlow = dfs(source, sink, INT_MAX, parent);
            }
        }

        return maxFlow;
    }
};

bool canSeatTeams(vector<int>& teamSizes, vector<int>& tableCapacities) {
    int n = teamSizes.size();
    int m = tableCapacities.size();

    // Create a flow network
    int source = n + m; // Source vertex index
    int sink = n + m + 1; // Sink vertex index
    FordFulkerson flowNetwork(n + m + 2);

    // Connect source to each team vertex with capacity equal to team size
    for (int i = 0; i < n; ++i) {
        flowNetwork.addEdge(source, i, teamSizes[i]);
    }

    // Connect each table vertex to sink with capacity equal to table capacity
    for (int j = 0; j < m; ++j) {
        flowNetwork.addEdge(n + j, sink, tableCapacities[j]);
    }

    // Connect each team vertex to each table vertex with capacity 1
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            flowNetwork.addEdge(i, n + j, 1);
        }
    }

    // Calculate the maximum flow in the flow network
    int maxFlow = flowNetwork.maxFlow(source, sink);

    // Check if all team members can be seated without violating table capacities
    return maxFlow == accumulate(teamSizes.begin(), teamSizes.end(), 0);
}

int main() {
    // Example usage
    vector<int> teamSizes = {3, 4, 2}; // Number of members in each team
    vector<int> tableCapacities = {4, 5, 3}; // Number of chairs at each table

    bool possible = canSeatTeams(teamSizes, tableCapacities);

    if (possible) {
        cout << "It is possible to seat all team members at different tables." << endl;
    } else {
        cout << "It is not possible to seat all team members at different tables." << endl;
    }

    return 0;
}
