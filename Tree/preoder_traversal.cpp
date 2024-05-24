#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node * left;
    Node * right;
};

Node * root;

Node * GetnewNode( int data )
{
    Node * newNode = new Node;
    newNode->data  = data;
    newNode->left  = NULL;
    newNode->right = NULL;
    return newNode;
}

Node * Insert( Node * root, int data )
{
    if( root == NULL )
    {
        root = GetnewNode( data );
        return root;
    }
    else if( data <= root->data )
    {
        root = Insert( root->left, data );
    }
    else
    {
        root = Insert( root->right, data );
    }
    return root;
}

Node * preorder( Node * root )
{
    if( root == NULL )
        return root;
    cout << root->data;
    preorder( root->left );
    preorder( root->right );
}

int main()
{
    root = NULL;
    root = Insert( root, 10 );
    root = Insert( root, 15 );
    root = Insert( root, 20 );
    root = Insert( root, 9 );
    root = Insert( root, 8 );

    return 0;
}
