#include <iostream>
using namespace std;
struct BstNode
{
    int data;
    BstNode * left;
    BstNode * right;
};
BstNode * GetNewNode( int data )
{
    BstNode * newNode = new BstNode;
    newNode->data     = data;
    newNode->left     = NULL;
    newNode->right    = NULL;
    return newNode;
}
BstNode * Insert( BstNode * root, int data )
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
}
int FindMin( BstNode * root )
{
    if( root == NULL ) /*Corner Case*/
    {
        cout << "Tree is empty";
        return -1;
    }
    while( root->left != NULL )
    {
        root = root->left;
    }
    return root->data;
}

int FindMax( BstNode * root )
{
    if( root == NULL ) /*Corner Case*/
    {
        cout << "Tree is empty";
        return -1;
    }
    while( root->right
           != NULL ) /* Loop traversing till it does not reaches the end of the tree in the right hand side*/
    {
        root = root->right;
    }
    return root->data;
}
int main()
{
    BstNode * root = NULL;
    root           = Insert( root, 15 );
    root           = Insert( root, 10 );
    root           = Insert( root, 20 );
    root           = Insert( root, 8 );
    root           = Insert( root, 12 );
    root           = Insert( root, 17 );
    root           = Insert( root, 25 );
    cout << "Min value element in the BST is " << FindMin( root ) << endl;
    cout << "Max value element in the BST is " << FindMax( root ) << endl;

    return 0;
}
