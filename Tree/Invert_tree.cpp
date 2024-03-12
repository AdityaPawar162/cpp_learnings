#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void inorderTraversal(Node* root) {
    if (root == nullptr) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

Node* invertTree(Node* root) {
    if (root == nullptr) return nullptr;

    // Swap left and right subtrees
    Node* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // Recursively invert left and right subtrees
    invertTree(root->left);
    invertTree(root->right);

    return root;
}

int main() {
    // Constructing the binary tree
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(6);
    root->right->right = new Node(9);

    cout << "Original Tree (Inorder traversal): ";
    inorderTraversal(root);
    cout << endl;

    // Inverting the binary tree
    root = invertTree(root);

    cout << "Inverted Tree (Inorder traversal): ";
    inorderTraversal(root);
    cout << endl;


    return 0;
}
