#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

Node* LCA(Node* root, Node* p, Node* q) {
    if (root == nullptr || root == p || root == q) {
        return root;
    }

    Node* left = LCA(root->left, p, q);
    Node* right = LCA(root->right, p, q);

    if (left == nullptr) return right;
    if (right == nullptr) return left;

    return root;
}

int main() {
    // Constructing the binary tree
    Node* root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->right->left = new Node(0);
    root->right->right = new Node(8);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);

    // Nodes for which LCA needs to be found
    Node* p = root->left;
    Node* q = root->right;

    // Find the LCA of nodes p and q
    Node* lcaNode = LCA(root, p, q);

    if (lcaNode != nullptr) {
        cout << "Lowest Common Ancestor of " << p->data << " and " << q->data << " is: " << lcaNode->data << endl;
    } else {
        cout << "One or both nodes not found in the tree!" << endl;
    }

    // Deallocating memory
    // Implementation of deallocation is not included here for simplicity
    // It's typically done using post-order traversal to delete each node

    return 0;
}
