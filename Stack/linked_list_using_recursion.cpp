#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node * next;
};
Node * Insert( Node * head, int data )
{
    Node * temp = new Node;
    temp->data  = data;
    temp->next  = NULL;
    if( head == NULL )
        head = temp;
    else
    {
        Node * temp1 = head;
        while( temp1->next != NULL )
            temp1 = temp1->next;
        temp1->next = temp;
    }
    return head;
}
void Print( struct Node * p )
{
    if( p == NULL )
        return;
    //	cout << p->data;
    Print( p->next );
    cout << p->data;
}

int main()
{
    struct Node * head = NULL;
    head               = Insert( head, 2 );
    head               = Insert( head, 4 );
    head               = Insert( head, 5 );
    head               = Insert( head, 6 );
    head               = Insert( head, 7 );
    Print( head );
}
