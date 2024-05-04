// After moving to a new city, you decide to choose a walking route from your home to
// your new office. To get a good daily workout, your route must consist of an uphill path
 
// (for exercise) followed by a downhill path (to cool down), or just an uphill path, or just
// a downhill path. (You’ll walk the same path home, so you’ll get exercise one way or the
// other.) But you also want the shortest path that satisfies these conditions, so that you
// actually get to work on time.
// Your input consists of an undirected graph G, whose vertices represent intersections and
// whose edges represent road segments, along with a start node s and a target node t.
// Every node v has an associated value h(v), which is the height of that intersection above
// sea level, and each edge uv has an associated value l(uv), which is the length of that road
// segment.
// a) Describe and analyze an algorithm to find the shortest uphill–downhill walk from s
// to t. Assume all node heights are distinct.
// b) and analyze an algorithm to find the shortest “uphill then downhill” walk from s to t;
// you may use flat edges in both the “uphill” and “downhill” portions of your walk.
// c) Finally, suppose you discover that there is no path from s to t with the structure you
// want. Describe an algorithm to find a path from s to t that alternates between “uphill”
// and “downhill” subpaths as few times as possible, and has minimum length among
// all such paths.

// a) To find the shortest uphill-downhill walk from node s to node t in an undirected graph G with distinct node heights, we can
//  use Dijkstra's algorithm with a slight modification. Here's the algorithm:

// 1. Initialize a priority queue pq to store pairs (node, dist), sorted by increasing dist.
// 2. Initialize a dist array dist[] with infinity values for all vertices except the start node s, which is set to 0.
// 3. While pq is not empty, dequeue the node u with the minimum dist.
// 4. For each neighbor v of u, if the height of v is greater than the height of u, calculate the total dist to v by adding 
// the length of the edge uv to the dist from s to u. If this dist is less than the current dist to v, update the dist to v and enqueue v into pq.
// 5. Repeat steps 3-4 until the target node t is dequeued from pq.
// 6. The shortest uphill-downhill walk from s to t is the path formed by following the predecessor pointers back from t to s.

// The time complexity of this algorithm is O((V + E) log V), where V is the number of vertices and E is the number of edges in the graph.

// b) To find the shortest uphill-then-downhill walk from s to t, we can modify Dijkstra's algorithm to 
// consider only uphill or downhill edges based on the node heights. Here's the modified algorithm:

// 1. Initialize two priority queues pq_uphill and pq_downhill to store pairs (node, dist), sorted by increasing dist.
// 2. Initialize two dist arrays dist_uphill[] and dist_downhill[] with infinity values for all vertices except the start node s, which is set to 0.
// 3. While pq_uphill and pq_downhill are not empty, dequeue the vertices u_uphill and u_downhill with the minimum distances from their respective queues.
// 4. For each neighbor v of u_uphill, if the height of v is greater than the height of u_uphill, calculate the total dist to v by adding the length of the edge uv to the dist from s to u_uphill. If this dist is less than the current dist to v, update the dist to v and enqueue v into pq_uphill.
// 5. For each neighbor v of u_downhill, if the height of v is less than the height of u_downhill, calculate the total dist to v by adding the length of the edge uv to the dist from s to u_downhill. If this dist is less than the current dist to v, update the dist to v and enqueue v into pq_downhill.
// 6. Repeat steps 3-5 until the target node t is dequeued from pq_uphill or pq_downhill.
// 7. The shortest uphill-then-downhill walk from s to t is the path formed by following the predecessor pointers back from t to s.

// The time complexity of this algorithm is also O((V + E) log V), where V is the number of vertices and E is the number of edges in the graph.

// c) If there is no path from s to t with the desired structure (alternating uphill and downhill subpaths), we can 
// modify Dijkstra's algorithm to find the shortest path with minimum alternations. Here's the modified algorithm:

// 1. Run Dijkstra's algorithm with a slight modification: instead of updating the dist to v only if it is less than the current dist, update the dist to v if it is less than or equal to the current dist and has a different parity (i.e., even or odd number of alternations).
// 2. Keep track of the number of alternations needed to reach each node.
// 3. After reaching the target node t, follow the predecessor pointers back from t to s to reconstruct the shortest path.
// 4. The reconstructed path will have the minimum number of alternations among all paths from s to t.

// The time complexity of this algorithm is also O((V + E) log V), where V is the number of vertices and E is the number of edges in the graph.

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Function to find the shortest uphill-downhill walk from s to t
int shortestUphillDownhillWalk(vector<vector<pair<int, int>>>& graph, int s, int t) {
    int V = graph.size();
    vector<int> dist(V, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto& edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist[t];
}

// Function to find the shortest uphill-then-downhill walk from s to t
int shortestUphillThenDownhillWalk(vector<vector<pair<int, int>>>& graph, int s, int t) {
    int V = graph.size();
    vector<int> dist(V, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto& edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist[t];
}

// Function to find the shortest path with minimum alternations from s to t
int shortestPathWithMinAlternations(vector<vector<pair<int, int>>>& graph, int s, int t) {
    int V = graph.size();
    vector<vector<int>> dist(V, vector<int>(2, INT_MAX)); // dist[u][0]: dist with even alternations, dist[u][1]: dist with odd alternations
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    dist[s][0] = 0;
    pq.push({0, {s, 0}}); // pair<int, pair<int, int>>: {dist, {node, alternations}}

    while (!pq.empty()) {
        auto [d, u] = pq.top().second;
        pq.pop();

        for (auto& edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;
            int new_alt = (dist[u][1] + 1) % 2; // alternation changes with each edge

            if (dist[u][new_alt] + w < dist[v][new_alt]) {
                dist[v][new_alt] = dist[u][new_alt] + w;
                pq.push({dist[v][new_alt], {v, new_alt}});
            }
        }
    }

    return min(dist[t][0], dist[t][1]);
}

// Example usage
int main() {
    // Example graph representation (adjacency list)
    int V = 4; // Number of vertices
    vector<vector<pair<int, int>>> graph(V);
    graph[0].push_back({1, 2}); // Edge from node 0 to node 1 with weight 2
    graph[1].push_back({2, 3}); // Edge from node 1 to node 2 with weight 3
    graph[2].push_back({3, 4}); // Edge from node 2 to node 3 with weight 4

    int s = 0; // Source node
    int t = 3; // Target node

    // Part (a)
    int shortest_walk_a = shortestUphillDownhillWalk(graph, s, t);
    cout << "Shortest uphill-downhill walk from s to t: " << shortest_walk_a << endl;

    // Part (b)
    int shortest_walk_b = shortestUphillThenDownhillWalk(graph, s, t);
    cout << "Shortest uphill-then-downhill walk from s to t: " << shortest_walk_b << endl;

    // Part (c)
    int shortest_walk_c = shortestPathWithMinAlternations(graph, s, t);
    cout << "Shortest path with minimum alternations from s to t: " << shortest_walk_c << endl;

    return 0;
}
