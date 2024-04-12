// 6. The transitive closure GT of a directed graph G is a directed graph with the same vertices
// as G, that contains any edge u→v if and only if there is a directed path from u to v in G.
// A transitive reduction of G is a graph with the smallest possible number of edges whose
// transitive closure is GT

// . The same graph may have several transitive reductions.

// a) Describe an efficient algorithm to compute the transitive closure of a given directed
// graph.
// b) Prove that a directed graph G has a unique transitive reduction if and only if G is
// acyclic.
// c) Describe an efficient algorithm to compute a transitive reduction of a given directed
// graph.
### 6. Transitive Closure and Transitive Reduction

#### a) Algorithm to Compute Transitive Closure

To compute the transitive closure of a given directed graph efficiently, we can use the Floyd-Warshall algorithm, which has a time complexity of O(V^3), where V is the number of vertices in the graph.

The steps of the algorithm are as follows:

1. Initialize a matrix T of size V x V where T[i][j] = 1 if there is a directed path from vertex i to vertex j, and T[i][j] = 0 otherwise.
2. Initialize T[i][j] = 1 if there is an edge from i to j in the given graph.
3. Iterate over all pairs of vertices i and j, and for each pair, update T[i][j] = 1 if there exists a
