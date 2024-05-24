#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node * next;
};
Node * Insert( Node * head, int n )
{
    Node * temp = new Node();
    temp->data  = n;
    temp->next  = NULL;
    if( head == NULL )
        head = temp;
    else
    {
        Node * temp1 = head;
        while( temp1 != NULL )
            temp1->next = temp1;
        temp1 = temp1->next;
    }
    return head;
}
void Print( Node * head )
{
    while( head != NULL )
    {
        Print( head->next );
        cout << head->data;
        //		head = head->next;
    }
}
Node * Reverse( Node * head )
{
    Node *current, *prev, *next;
    current = head;
    prev    = NULL;
    while( current != head )
    {
        next          = current->next;
        current->next = prev;
        current       = next;
        prev          = current;
    }
    return head;
}
int main()
{
    Node * head = NULL;
    head        = Insert( head, 2 );
    head        = Insert( head, 4 );
    head        = Insert( head, 6 );
    head        = Insert( head, 5 );
    Print( head );
    head = Reverse( head );
    Print( head );
}
