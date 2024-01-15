BFS(G, s)
for all u ∈ V(G) do
    Color[u] = white;
end
Color[s] = grey;
Layer(s) = 0;
Queue Q ← ∅;
parent(s) = NULL;
EnQueue(Q, s);

while Q is not empty do
    u ← DeQueue(Q);
    for each v ∈ Adj(u) do
        if v is white then
            Color[v] = grey;
            Layer(v) = Layer(u) + 1;
            parent(v) = u;
            EnQueue(Q, v);
        end
    end
    Color[u] = black;
end

Explanation:

Initialize all vertices to the 'white' color, indicating they haven't been visited.
Set the color of the source vertex s to 'grey', indicating it's the current focus.
Set the layer of the source vertex s to 0.
Initialize an empty queue Q to keep track of vertices to visit.
Set the parent of the source vertex s to NULL.
Enqueue the source vertex s into the queue.
While the queue is not empty:
a. Dequeue a vertex u from the front of the queue.
b. For each neighbor v of u:
If v is white (unvisited):
Set the color of v to 'grey'.
Set the layer of v to the layer of u + 1.
Set the parent of v to u.
Enqueue v into the queue.
c. Set the color of u to 'black', indicating it has been fully explored.
This BFS implementation traverses the graph in layers, starting from the source vertex s. The layers are defined by the distance from the source vertex. The queue ensures that vertices are processed in the order they are discovered.