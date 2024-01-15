## Bipartite Graph Detection Algorithm

### Algorithm 1: Modified BFS

```python
BFS(G, s)
For all v ∈ V, color v white;
Color u grey; Layer(s) = 0; Initialize queue Q ← ∅; parent(s) = NULL;
while Q is not empty do
    u ← DeQueue(Q);
    for each v ∈ Adj(u) do
        if v is white then
            Color v grey; Layer(v) = Layer(u) + 1;
            parent(v) = u; EnQueue(Q, v);
        else
            if Layer(u) = Layer(v) then
                Output "There is an odd cycle";
            end
        end
    end
    Color u black;
end
Output "G is bipartite graph";
```

Algorithm 2: Bipartite Graph Check
python
Copy code
# Stage 1: Invoke BFS(G, s) and compute Layer(v) for all v ∈ V.
# Stage 2: For every edge (u, v) ∈ E, check if Layer(u) = Layer(v).
# If for all (u, v) ∈ E, Layer(u) ≠ Layer(v), then output that G is bipartite graph.
# Otherwise, there is (u, v) ∈ E such that Layer(u) = Layer(v). Output that G is not bipartite.

# Pseudocode
Invoke BFS(G, s)  # Stage 1

# Stage 2
for each edge (u, v) in E do
    if Layer(u) = Layer(v) then
        Output "G is not bipartite graph";
    end
end
Output "G is bipartite graph";