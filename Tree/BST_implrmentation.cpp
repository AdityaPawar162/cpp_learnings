#include <iostream>
using namespace std;
struct BstNode
{
    int data;
    BstNode * left;
    BstNode * right;
};

BstNode * GetnewNode( int n )
{
    BstNode * newNode = new BstNode();
    newNode->data     = n;
    newNode->left     = NULL;
    newNode->right    = NULL;

    return newNode;
}

BstNode * Insert( BstNode * root, int data )
{
    if( root == NULL )
    { // At the start
        root = GetnewNode( data );
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
BstNode * PrintNode( BstNode * root )
{
    cout << "Value at the node" << root->data << endl;
    if( root->left != NULL )
    {
        cout << "Value	at the left node" << root->left->data << " " << endl;
    }

    if( root->right != NULL )
    {
        cout << "Value	at the right node" << root->right->data << " " << endl;
    }
}

bool Search( BstNode * root, int data )
{
    if( root == NULL )
        return false;
    else if( root->data == data )
        return true;
    else if( data <= root->data )
        Search( root->left, data );
    else
        Search( root->right, data );
}
int main()
{
    BstNode * root = NULL;
    root           = Insert( root, 10 );
    root           = Insert( root, 15 );
    root           = Insert( root, 20 );
    root           = Insert( root, 9 );
    root           = Insert( root, 8 );
    if( Search( root, 20 ) == true )
        cout << "Found\n";
    else
        cout << "Not Found\n";
    // cout << Search(root,20);
    // root = PrintNode(root);
    return 0;
}
