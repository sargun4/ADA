// 7. You have a collection of n lock-boxes and m gold keys. Each key unlocks at most one box.
// However, each box might be unlocked by one key, by multiple keys, or by no keys at all.
// There are only two ways to open each box once it is locked: Unlock it properly (which
// requires having one matching key in your hand), or smash it to bits with a hammer.
// Your baby brother, who loves playing with shiny objects, has somehow managed to lock
// all your keys inside the boxes! Luckily, your home security system recorded everything,
// so you know exactly which keys (if any) are inside each box. You need to get all the keys
// back out of the boxes, because they are made of gold. Clearly you have to smash at least
// one box.
// a) Your baby brother has found the hammer and is eagerly eyeing one of the boxes.
// Describe and analyze an algorithm to determine if it is possible to retrieve all the keys
// without smashing any box except the one your brother has chosen.
// b) Describe and analyze an algorithm to compute the minimum number of boxes that
// must be smashed to retrieve all the keys.


// 7. Retrieving Keys from Lock-Boxes
// a) Algorithm to Determine Feasibility without Smashing More Boxes
// To determine if it's possible to retrieve all the keys without smashing any box except the one your brother has chosen, we can use a depth-first search (DFS) algorithm.

// Here's the algorithm:

// Initialize a boolean array vis[] of size 
// n to keep track of whether each box has been vis.
// Mark the box chosen by your brother as vis.
// Perform a DFS traversal starting from the box chosen by your brother:
// a. For each box i connected to the curr box u:
// If i has not been vis:
// Mark i as vis.
// Recursively explore i.
// After the DFS traversal, if all boxes have been vis, return true (it's possible to retrieve all the keys without smashing any 
// additional boxes); otherwise, return false.
// This algorithm explores all connected boxes starting from the one chosen by your brother. If it manages to visit all boxes, it means it's possible
//  to retrieve all the keys without smashing any additional boxes.

// b) Algorithm to Compute Minimum Boxes to Smash
// To compute the minimum number of boxes that must be smashed to retrieve all the keys, we can use a variation of depth-first search (DFS) algorithm.

// Here's the algorithm:

// Initialize a boolean array 
// vis[] of size 
// n to keep track of whether each box has been vis.
// Initialize a variable 
// smashedCount
// smashedCount to 0 to keep track of the number of boxes smashed.
// Perform a DFS traversal starting from each box:
// a. If the curr box 
// u has not been vis:
// Increment 
// smashedCount
// smashedCount by 1 (smash the box).
// Mark u as vis.
// Recursively explore all boxes reachable from u.
// After the DFS traversal, return 
// smashedCount−1, as the first box doesn't need to be smashed.

#include <iostream>
#include <vector>

using namespace std;

// Data structure to represent a lock-box
struct LockBox {
    vector<int> keysInside;
};

// Depth-first search to explore connected boxes
void dfs(vector<LockBox>& lockBoxes, vector<bool>& vis, int curr) {
    vis[curr] = true;
    for (int box : lockBoxes[curr].keysInside) {
        if (!vis[box]) {
            dfs(lockBoxes, vis, box);
        }
    }
}

// Algorithm to determine feasibility without smashing more boxes
bool canRetrieveKeysWithoutSmashing(vector<LockBox>& lockBoxes, int brotherChosenBox) {
    int n = lockBoxes.size();
    vector<bool> vis(n, false);
    vis[brotherChosenBox] = true;
    dfs(lockBoxes, vis, brotherChosenBox);

    for (bool v : vis) {
        if(!v) return false;// Some boxes were not vis
    }
    return true; // All boxes were vis
}

// Algorithm to compute minimum boxes to smash
int minimumBoxesToSmash(vector<LockBox>& lockBoxes) {
    int n = lockBoxes.size();
    vector<bool> vis(n, false);
    int smashedCount = 0;

    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            smashedCount++; // Smash the box
            dfs(lockBoxes, vis, i);
        }
    }

    return smashedCount - 1; // Return smashed count minus one for the first box
}

int main() {
    // Example usage
    vector<LockBox> lockBoxes = {
        {{1, 2}},   // Box 0 contains keys for boxes 1 and 2
        {{3}},      // Box 1 contains a key for box 3
        {{3}},      // Box 2 contains a key for box 3
        {{}}        // Box 3 contains no keys
    };

    int brotherChosenBox = 0; // Box chosen by your brother to smash

    cout << "Feasibility without smashing more boxes: ";
    if (canRetrieveKeysWithoutSmashing(lockBoxes, brotherChosenBox)) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    cout << "Minimum boxes to smash: " << minimumBoxesToSmash(lockBoxes) << endl;

    return 0;
}
