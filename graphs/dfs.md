DFS(G, v)
    for all u ∈ V(G) do
        Color[u] = white;
        parent[u] = NULL;
    end
    DFS-Visit(v);

DFS-Visit(u)
    Color[u] = grey;
    for each v ∈ Adj(u) do
        if Color[v] is white then
            parent[v] = u;
            DFS-Visit(v);
        end
    end
    Color[u] = black;
    
Explanation:

DFS function initializes the color and parent arrays for all vertices and then calls DFS-Visit on the starting vertex v.
DFS-Visit is a recursive function that explores the vertices in depth. It starts by marking the current vertex u as 'grey', indicating it is being visited.
For each adjacent vertex v of u, if v is white (unvisited), then:
Set the parent of v to u.
Recursively call DFS-Visit on v.
After all adjacent vertices are visited, mark the current vertex u as 'black', indicating it has been fully explored.
This DFS implementation explores as far as possible along each branch before backtracking. The Color array is used to keep track of the visited status of vertices, and the parent array is used to store the parent of each vertex in the DFS traversal tree.

 