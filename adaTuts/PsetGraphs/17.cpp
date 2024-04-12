// 17. The first morning after returning from a glorious spring break, Alice wakes to discover
// that her car won’t start, so she has to get to her classes at Sham-Poobanana University
// by public transit. She has a complete transit schedule for Poobanana County. The bus
// routes are represented in the schedule by a directed graph G, whose vertices represent bus
// stops and whose edges represent bus routes between those stops. For each edge u→v, the
// schedule records three positive real numbers:
// • l(u→v) is the length of the bus ride from stop u to stop v (in minutes)
// • f(u→v) is the first time (in minutes past 12am) that a bus leaves stop u for stop v.
// • ∆(u→v) is the time between successive departures from stop u to stop v (in minutes).
// Thus, the first bus for this route leaves u at time f(u→v) and arrives at v at time(u→v)+l(u→v),
// the second bus leaves u at time f(u→v)+∆(u→v) and arrives at v at time f(u→v)+∆(u→v)+l(u→v),
// the third bus leaves u at time f(utov)+2·∆(u→v) and arrives at v at time f(u→v)+2·∆(u→v)+l(u→v),
// and so on.
// Alice wants to leaves from stop s (her home) at a certain time and arrive at stop t (The
// See-Bull Center) as quickly as possible. If Alice arrives at a stop on one bus at the exact
// time that another bus is scheduled to leave, she can catch the second bus. Because she’s a
// student at SPU, Alice can ride the bus for free, so she doesn’t care how many times she has
// to change buses.
// Describe and analyze an algorithm to find the earliest time Alice can reach her destination.
// Your input consists of the directed graph G = (V, E), the vertices s and t, the values l(e),
// f(e), ∆(e) for each edge e ∈ E, and Alice’s starting time (in minutes past 12am).
// [Hint: In this rare instance, it may be easier to modify the algorithm, instead of modifying
// the input graph.]

// To find the earliest time Alice can reach her destination using the provided bus schedule, we can modify
//  Dijkstra's algorithm to consider the time constraints at each bus stop. Here's the algorithm:

// Initialize a priority queue pq to store pairs (time, vertex), sorted by increasing time.
// Initialize a distance array dist[] with infinity values for all vertices except the start vertex s, which is
//  set to Alice's starting time.
// Enqueue the pair (start time, start vertex) into pq.
// While pq is not empty, dequeue the pair (time, u) with the minimum time.
// For each neighbor v of u, calculate the time when the next bus arrives at v from u based on the bus schedule.
// If this arrival time is earlier than the current time recorded in dist[v], update the arrival time in dist[v] 
// and enqueue the pair (arrival time, v) into pq.
// Repeat steps 4-6 until the destination vertex t is dequeued from pq.
// The earliest time Alice can reach her destination is the time recorded in dist[t].



#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int v; // Destination vertex
    double weight; // Length of the bus ride (in minutes)
    double departure_time; // Time when the bus leaves the source stop (in minutes past 12am)
    double interval; // Time between successive departures (in minutes)
};

// Function to find the earliest time Alice can reach her destination
double earliestArrivalTime(const vector<vector<Edge>>& graph, int s, int t, double start_time) {
    int V = graph.size();
    vector<double> dist(V, DBL_MAX);
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;

    dist[s] = start_time;
    pq.push({start_time, s});

    while (!pq.empty()) {
        double time = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (u == t) return dist[t];

        for (const auto& edge : graph[u]) {
            double next_departure_time = edge.departure_time;
            while (next_departure_time < time) {
                next_departure_time += edge.interval;
            }
            double arrival_time = next_departure_time + edge.weight;
            if (arrival_time < dist[edge.v]) {
                dist[edge.v] = arrival_time;
                pq.push({arrival_time, edge.v});
            }
        }
    }

    return -1; // Destination is unreachable
}

int main() {
    // Example graph representation (adjacency list)
    int V = 4; // Number of vertices
    vector<vector<Edge>> graph(V);
    // Add edges to the graph
    // Edge: (source, destination, length, departure time, interval)
    graph[0].push_back({1, 20, 10, 30});
    graph[0].push_back({2, 25, 5, 15});
    graph[1].push_back({3, 15, 0, 20});
    graph[2].push_back({3, 10, 0, 25});

    int s = 0; // Source vertex (Alice's home)
    int t = 3; // Target vertex (The See-Bull Center)
    double start_time = 0; // Alice's starting time (in minutes past 12am)

    double earliest_time = earliestArrivalTime(graph, s, t, start_time);
    if (earliest_time == -1) {
        cout << "Destination is unreachable\n";
    } else {
        cout << "Earliest time Alice can reach her destination: " << earliest_time << " minutes past 12am\n";
    }

    return 0;
}
