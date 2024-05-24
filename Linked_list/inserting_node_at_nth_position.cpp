#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node * link;
};
Node * head;
void Insert( int data, int n )
{
    Node * temp1 = new Node();
    temp1->data  = data;
    temp1->link  = NULL;
    if( n == 1 )
    {
        temp1->link = head;
        head        = temp1;
        return;
    }
    Node * temp2 = head;
    for( int i = 0; i < n - 2; i++ )
    {
        temp2 = temp2->link;
    }
    temp1->link = temp2->link;
    temp2->link = temp1;
}
void Print()
{
    Node * temp = head;
    cout << "The numbers in the list are:";
    while( temp != NULL )
    {
        cout << temp->data;
        temp = temp->link;
    }
    cout << "\n";
}
int main()
{
    head = NULL;
    Insert( 2, 1 ); // 2
    Insert( 3, 2 ); // 2,3
    Insert( 4, 1 ); // 4,2,3
    Insert( 5, 2 ); // 4,5,2,3
    Print();
}
