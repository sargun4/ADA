// 6. Given a vertex weighted rooted binary tree T whose weight function wt : T → R+. A set
// of vertices S ⊆ V(T) is called a dominating set if for every u ∈ V(T), either u ∈ S or there is
// v ∈ S such that (u, v) ∈ E(T). Informally speaking, a set S of vertices is a dominating set
// if every vertex u is either in S or has some neighbor v that is in S. The weight of a vertex
// subset S is denoted by wt(S) = ∑
// u∈S
// wt(u). A dominating set S of T is of minimum weight if it

// has smaller weight than any other dominating set of T.
// Design a dynamic programming based polynomial-time algorithm that computes the total
// weight of a minimum weighted dominating set of a binary tree.
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int weight;
    Node* left;
    Node* right;
    Node(int w) : weight(w), left(nullptr), right(nullptr) {}
};

// Memoization table to store computed results
unordered_map<Node*, int> memo;
// Function to compute the total weight of a minimum weighted dominating set
int minWeightDominatingSet(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    // Check if the result is already memoized
    if (memo.find(root) != memo.end()) {
        return memo[root];
    }

    // Calculate the weight when the root is included
    int includeRoot = root->weight;

    // Calculate the weight when the root is excluded
    if (root->left != nullptr) {
        includeRoot += minWeightDominatingSet(root->left->left) + minWeightDominatingSet(root->left->right);
    }

    if (root->right != nullptr) {
        includeRoot += minWeightDominatingSet(root->right->left) + minWeightDominatingSet(root->right->right);
    }

    // Calculate the weight when the root is excluded
    int excludeRoot = minWeightDominatingSet(root->left) + minWeightDominatingSet(root->right);

    // Memoize the result
    memo[root] = min(includeRoot, excludeRoot);

    return memo[root];
}

int main() {
    // Construct a sample binary tree
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(8);
    root->right->left = new Node(12);
    root->right->right = new Node(20);

    int result = minWeightDominatingSet(root);
    cout << "Total weight of minimum weighted dominating set: " << result << endl;

    return 0;
}
