
#include <bits/stdc++.h>
using namespace std; 
class Node{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
}; 

class Solution {
    void solve(Node* root, Node*& newNode) {
        if (root == NULL) {
            return;
        }
        solve(root->left, newNode);

        // Create a new node for the flattened list
        Node* temp = new Node(root->data);
        temp->left = NULL;
        temp->right = NULL;

        // Connect the new node to the flattened list
        if (newNode == NULL) {
            newNode = temp;
        } else {
            Node* current = newNode;
            while (current->right != NULL) {
                current = current->right;
            }
            current->right = temp;
        }

        solve(root->right, newNode);
    }

public:
    Node* flattenBST(Node* root) {
        Node* newNode = NULL;
        solve(root, newNode);
        return newNode;
    }
};