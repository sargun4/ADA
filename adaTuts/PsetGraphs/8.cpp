// 8. Suppose we are given both an undirected graph G with weighted edges and a minimum
// spanning tree T of G.
// a) Describe an algorithm to update the minimum spanning tree when the weight of a
// single edge e is decreased.
// b) Describe an algorithm to update the minimum spanning tree when the weight of a
// single edge e is increased.
// In both cases, the input to your algorithm is the edge e and its new weight; your algorithms
// should modify T so that it is still a minimum spanning tree. [Hint: Consider the cases e ∈
// T and e /∈ T separately.]


// If 
// e is not part of 
// T, there is no need to update 
// T because the minimum spanning tree property is preserved.
// If 
// e is part of 
// T, remove 
// e from 
// T and perform a depth-first search (DFS) traversal from one endpoint of 
// e to detect any cycle formed due to the removal of 
// e.
// Among all the edges in the detected cycle, find the edge with the maximum weight. Let's call this edge 
// f.
// Add 
// e to 
// T and remove 
// f from 
// T. Now 
// T is still a spanning tree, and its weight is still minimized.
// b) Algorithm to Update Minimum Spanning Tree for Increased Edge Weight
// Given an undirected graph 
// G with weighted edges and a minimum spanning tree 
// T, if the weight of a single edge 
// e is increased, we need to update 
// T so that it remains a minimum spanning tree.

// Here's the algorithm:

// If 
// e is not part of 
// T, there is no need to update 
// T because the minimum spanning tree property is preserved.
// If 
// e is part of 
// T, remove 
// e from 
// T and perform a depth-first search (DFS) traversal from one endpoint of 
// e to detect any cycle formed due to the removal of 
// e.
// Among all the edges in the detected cycle, find the edge with the minimum weight. Let's call this edge 
// f.
// Add 
// e to 
// T and remove 
// f from 
// T. Now 
// T is still a spanning tree, and its weight is still minimized.
// Time Complexity Analysis
// Both algorithms have a time complexity of  
// O(V+E), where 
 #include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Data structure to represent an edge
struct Edge {
    int u, v, weight;
};

// Data structure to represent a disjoint-set
struct DisjointSet {
    vector<int> parent, rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    // Find the root of the set containing element x
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    // Union two sets by rank
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

// Function to update minimum spanning tree for decreased edge weight
void updateMSTForDecreasedWeight(vector<Edge>& T, const Edge& e) {
    auto it = find(T.begin(), T.end(), e);
    if (it == T.end()) return; // Edge e is not part of the MST

    T.erase(it); // Remove edge e from the MST

    // Detect cycle using DFS
    DisjointSet dsu(T.size() + 1); // Create a disjoint-set
    for (const auto& edge : T) {
        dsu.unite(edge.u, edge.v);
    }

    // Find the edge with maximum weight in the cycle
    int maxWeight = INT_MIN;
    Edge maxWeightEdge;
    for (const auto& edge : T) {
        if (dsu.find(edge.u) == dsu.find(edge.v) && edge.weight > maxWeight) {
            maxWeight = edge.weight;
            maxWeightEdge = edge;
        }
    }

    // Add edge e to the MST and remove the edge with maximum weight
    T.push_back(e);
    T.erase(find(T.begin(), T.end(), maxWeightEdge));
}

// Function to update minimum spanning tree for increased edge weight
void updateMSTForIncreasedWeight(vector<Edge>& T, const Edge& e) {
    auto it = find(T.begin(), T.end(), e);
    if (it == T.end()) return; // Edge e is not part of the MST

    T.erase(it); // Remove edge e from the MST

    // Detect cycle using DFS
    DisjointSet dsu(T.size() + 1); // Create a disjoint-set
    for (const auto& edge : T) {
        dsu.unite(edge.u, edge.v);
    }

    // Find the edge with minimum weight in the cycle
    int minWeight = INT_MAX;
    Edge minWeightEdge;
    for (const auto& edge : T) {
        if (dsu.find(edge.u) == dsu.find(edge.v) && edge.weight < minWeight) {
            minWeight = edge.weight;
            minWeightEdge = edge;
        }
    }

    // Add edge e to the MST and remove the edge with minimum weight
    T.push_back(e);
    T.erase(find(T.begin(), T.end(), minWeightEdge));
}

int main() { 
    vector<Edge> T = {
        {0, 1, 2},
        {1, 2, 3},
        {2, 3, 4}
    };

    Edge e1 = {1, 2, 1}; // Decreased weight
    updateMSTForDecreasedWeight(T, e1);

    Edge e2 = {0, 1, 4}; // Increased weight
    updateMSTForIncreasedWeight(T, e2);

    cout << "Minimum Spanning Tree after updating edge weights:\n";
    for (const auto& edge : T) {
        cout << edge.u << " - " << edge.v << " : " << edge.weight << endl;
    }

    return 0;
}
