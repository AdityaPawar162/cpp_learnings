#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node * left;
    Node * right;
};
Node * GetNewNode( int data )
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
        root = GetNewNode( data );
    }
    else if( data <= root->data )
    {
        root->left = Insert( root->left, data );
    }
    else
    {
        root->right = Insert( root->right, data );
    }

    return root;
}
int FindHeight( Node * root )
{
    if( root == NULL )
        return -1;

    return max( FindHeight( root->left ), FindHeight( root->right ) ) + 1;
}

int main()
{
    Node * root = NULL;
    root        = Insert( root, 10 );
    root        = Insert( root, 15 );
    root        = Insert( root, 20 );
    root        = Insert( root, 9 );
    root        = Insert( root, 8 );
    cout << FindHeight( root );
    return 0;
}
