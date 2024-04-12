// 15. There are n galaxies connected by m intergalactic teleport-ways. Each teleport-way joins
// two galaxies and can be traversed in both directions. Also, each teleport-way e has an
// associated cost of c(e) dollars, where c(e) is a positive integer. A teleport-way can be used
// multiple times, but the toll must be paid every time it is used.
// Judy wants to travel from galaxy s to galaxy t as cheaply as possible. However, she wants
// the total cost to be a multiple of 5 dollars, because carrying small change is not pleasant
// either.
// a) Describe and analyze an algo to compute the minimum total cost of traveling
// from galaxy s to galaxy t, subject to the restriction that the total cost is a multiple of
// 5 dollars.
// b) Solve part (a), but now assume that Judy has a coupon that allows her to use exactly
// one teleport-way for free.


// a) To compute the minimum total cost of traveling from galaxy s to galaxy t while ensuring that the total cost is a multiple of
//  5 dollars, we can modify Dijkstra's algo to keep track of the minimum cost % 5 at each vertex. Here's the algo:

// 1. Initialize an array `dist[V][5]` to store the minimum cost % 5 to reach each vertex v, where V is the no of galaxies and 5
//  represents the possible remainders when divided by 5. Initialize `dist[v][r] = ∞` for all vertices v and remainders r.
// 2. Initialize a priority queue `pq` to store pairs `(v, r)`, where v is the vertex and r is the remainder of the cost % 5.
// 3. Add the source vertex s to `pq` with cost 0 and remainder 0.
// 4. While `pq` is not empty, dequeue the pair `(v, r)` with the minimum total cost % 5.
// 5. For each neighbor u of v, update `dist[u][r']` if `dist[v][r] + cost(v, u)` is less than `dist[u][r']`, where 
// `r' = (dist[v][r] + cost(v, u)) % 5`.
// 6. If u is updated, enqueue `(u, r')` into `pq`.
// 7. After processing all vertices, `dist[t][0]` will contain the minimum total cost % 5 to reach galaxy t.

// b) To solve part (a) with the additional constraint that Judy has a coupon allowing her to use one teleport-way for
//  free, we can modify the algo as follows:

// 1. Initialize an array `dist[V][5][2]` to store the minimum cost % 5 to reach each vertex v, considering whether the coupon
//  has been used or not. Initialize `dist[v][r][0] = ∞` and `dist[v][r][1] = ∞` for all vertices v and remainders r.
// 2. Initialize a priority queue `pq` to store triples `(v, r, k)`, where v is the vertex, r is the remainder of the cost % 5,
//  and k indicates whether the coupon has been used (0 for not used, 1 for used).
// 3. Add the source vertex s to `pq` with cost 0, remainder 0, and coupon state 0.
// 4. While `pq` is not empty, dequeue the triple `(v, r, k)` with the minimum total cost % 5.
// 5. For each neighbor u of v, update `dist[u][r'][k']` if `dist[v][r][k] + cost(v, u)` is less than `dist[u][r'][k']`, 
// where `r' = (dist[v][r][k] + cost(v, u)) % 5` and `k' = (k + 1) % 2`.
// 6. If u is updated, enqueue `(u, r', k')` into `pq`.
// 7. After processing all vertices, `dist[t][0][0]` will contain the minimum total cost % 5 to reach galaxy t without
//  using the coupon, and `dist[t][0][1]` will contain the minimum total cost % 5 to reach galaxy t using the coupon. 
// Return the minimum of these two values.


// a) Minimum total cost with total cost being a multiple of 5 dollars
 #include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Function to compute the minimum total cost from source s to target t
int minTotalCost(const vector<vector<pair<int, int>>>& graph, int s, int t) {
    int V = graph.size();
    vector<vector<int>> dist(V, vector<int>(5, INT_MAX));
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

    dist[s][0] = 0;
    pq.push({0, s, 0});

    while (!pq.empty()) {
        auto [c, u, r] = pq.top();
        pq.pop();

        if (c > dist[u][r]) continue;

        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;
            int r_new = (r + w) % 5;
            int c_new = c + w;

            if (c_new < dist[v][r_new]) {
                dist[v][r_new] = c_new;
                pq.push({c_new, v, r_new});
            }
        }
    }

    int min_cost = INT_MAX;
    for (int i = 0; i < 5; ++i) {
        min_cost = min(min_cost, dist[t][i]);
    }

    return min_cost;
}
 

// b) Minimum total cost with total cost being a multiple of 5 dollars and a free coupon
 
// Function to compute the minimum total cost with a free coupon
int minTotalCostWithCoupon(const vector<vector<pair<int, int>>>& graph, int s, int t) {
    int V = graph.size();
    vector<vector<vector<int>>> dist(V, vector<vector<int>>(5, vector<int>(2, INT_MAX)));
    priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> pq;

    dist[s][0][0] = 0;
    pq.push({0, s, 0, 0});

    while (!pq.empty()) {
        auto [c, u, r, k] = pq.top();
        pq.pop();

        if (c > dist[u][r][k]) continue;

        for (const auto& edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;
            int r_new = (r + w) % 5;
            int c_new = c + w;
            int k_new = (k + 1) % 2;

            if (c_new < dist[v][r_new][k_new]) {
                dist[v][r_new][k_new] = c_new;
                pq.push({c_new, v, r_new, k_new});
            }
        }
    }

    return min(dist[t][0][0], dist[t][0][1]);
}

// Example usage
int main() {
    int V = 4; // Number of galaxies
    vector<vector<pair<int, int>>> graph(V);

    // Example graph representation (adjacency list)
    graph[0].push_back({1, 3}); // Edge from galaxy 0 to galaxy 1 with cost 3
    graph[0].push_back({2, 5}); // Edge from galaxy 0 to galaxy 2 with cost 5
    graph[1].push_back({3, 2}); // Edge from galaxy 1 to galaxy 3 with cost 2
    graph[2].push_back({3, 4}); // Edge from galaxy 2 to galaxy 3 with cost 4

    int s = 0; // Source galaxy
    int t = 3; // Target galaxy

    // Part (a)
    int min_cost_a = minTotalCost(graph, s, t);
    cout << "Minimum total cost (multiple of five dollars): " << min_cost_a << endl;

    // Part (b)
    int min_cost_b = minTotalCostWithCoupon(graph, s, t);
    cout << "Minimum total cost with coupon (multiple of five dollars): " << min_cost_b << endl;

    return 0;
}
