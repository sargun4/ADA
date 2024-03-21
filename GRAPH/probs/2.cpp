// 2. Suppose there are n cities connected by highways (not necessarily
// there is a straight road between every pair of cities). Suppose two of
// your friends started exploring by cars and in every step each of them
// can move from city A to city B if the cities have a direct road between
// them.
// Design an algorithm to compute minimum number of steps needed
// for them to meet at the same city or to report that no such paths are
// possible.

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

vector<int> minStepsToMeet(const vector<vector<int>>& graph, int start1, int start2) {
    int n = graph.size();
    vector<int> steps(n, -1);
    queue<int> q;
    unordered_set<int> visited;

    q.push(start1);
    q.push(start2);
    steps[start1] = 0;
    steps[start2] = 0;
    visited.insert(start1);
    visited.insert(start2);

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : graph[current]) {
            if (visited.find(neighbor) == visited.end()) {
                q.push(neighbor);
                visited.insert(neighbor);
                steps[neighbor] = steps[current] + 1;
            }
        }
    }

    return steps;
}

int main() {
    // Example usage
    vector<vector<int>> graph = {
        {1, 2},     // City 0 connected to cities 1 and 2
        {0, 3},     // City 1 connected to cities 0 and 3
        {0, 4},     // City 2 connected to cities 0 and 4
        {1},        // City 3 connected to city 1
        {2}         // City 4 connected to city 2
    };

    vector<int> steps = minStepsToMeet(graph, 0, 3);

    cout << "Minimum steps needed to meet: " << steps[3] << endl;

    return 0;
}


// Start BFS from both friends' cities simultaneously.
// At each step, expand the search to all cities reachable from the current cities.
// Keep track of the cities visited by both friends.
// If they reach the same city at any step, return the step count.
// If there are no more cities to explore and they haven't met, return that no such paths are possible.