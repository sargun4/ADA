# Types of Tree Edges with Layer and Distance Definitions

## Tree Edge:
- **Definition:** An edge (u, v) is a tree edge if the distance from the source s to v is one more than the distance from s to u. In terms of layers, this means that the layer of v is equal to the layer of u plus 1.
- **Mathematically:** `dist(s, v) = dist(s, u) + 1` or `Layer(v) = Layer(u) + 1`

## Cross Edge:
- **Definition:** An edge (u, v) is a cross edge if the layers of vertices u and v are either equal or differ by one. In terms of distances, this means that the distance from s to v is equal to or one more than the distance from s to u.
- **Mathematically:** `Layer(v) = Layer(u)` or `Layer(v) = Layer(u) + 1`

## Back Edge:
- **Definition:** An edge (u, v) is a back edge if it connects a vertex u to one of its ancestors v in the tree. In terms of distances, this implies that the distance from the source s to v is less than the distance from s to u, indicating a cycle.
- **Mathematically:** `dist(s, v) < dist(s, u)` or `Layer(v) < Layer(u)`

## Forward Edge:
- **Definition:** An edge (u, v) is a forward edge if it connects a vertex u to one of its descendants v in the tree. In terms of distances, this means that the distance from the source s to v is greater than the distance from s to u.
- **Mathematically:** `dist(s, v) > dist(s, u)` or `Layer(v) > Layer(u)`
