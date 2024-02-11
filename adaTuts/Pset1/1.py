# // 1. Given an undirected graph G = (V, E) and two specified vertices u and v. Design
# // an algorithm that computes the number of shortest paths between u and v in G.
# // Your algorithm does not have to list all shortest paths between u and v in G, just the
# // number of shortest paths between u and v suffices. By definition, a shortest path
# // between u and v is a path between u and v with minimum number of edges.

# Algorithm for Counting Shortest Paths:

# To compute the number of shortest paths between two specified vertices u and v in an 
# undirected graph G = (V, E), you can use Dijkstra's algorithm with some modifications.
#  The key is to maintain a count of the number of shortest paths to each vertex.
 
from collections import defaultdict
import heapq

def count_shortest_paths(graph, u, v):
    # Initialize dists and counts
    dists = {vertex: float('inf') for vertex in graph}
    counts = {vertex: 0 for vertex in graph}
    dists[u] = 0
    counts[u] = 1

    # Priority queue to keep track of vertices and their dists
    priority_queue = [(0, u)]

    while priority_queue:
        current_distance, current_vertex = heapq.heappop(priority_queue)

        # Relaxation step
        for neighbor in graph[current_vertex]:
            if dists[current_vertex] + 1 < dists[neighbor]:
                dists[neighbor] = dists[current_vertex] + 1
                counts[neighbor] = counts[current_vertex]
                heapq.heappush(priority_queue, (dists[neighbor], neighbor))
            elif dists[current_vertex] + 1 == dists[neighbor]:
                counts[neighbor] += counts[current_vertex]

    return counts[v]
 
graph = {
    1: [2, 3],
    2: [1, 4],
    3: [1, 4],
    4: [2, 3, 5],
    5: [4]
}
u, v = 1, 5
result = count_shortest_paths(graph, u, v)
print(f"Number of shortest paths from {u} to {v}: {result}")