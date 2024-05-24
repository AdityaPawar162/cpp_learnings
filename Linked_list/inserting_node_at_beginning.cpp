#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node * link;
};
Node * A;
void Insert( int x )
{
    Node * temp = new Node();
    temp->data  = x;
    temp->link  = A;
    A           = temp;
}
void Print()
{
    Node * temp = A;
    cout << "List is: " << endl;
    while( temp != NULL )
    {
        cout << int( temp->data ) << "\t";
        temp = temp->link;
    }
    cout << "\n" << endl;
}

int main()
{
    A = NULL;
    int n, x;
    cout << "How many numbers: " << endl;
    cin >> n;
    for( int i = 0; i <= n; i++ )
    {
        cout << "Enter the number" << endl;
        cin >> x;
        Insert( x );
        Print();
    }
}
