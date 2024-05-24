#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node * link;
};
// Node*A; *********************IF HEAD IS DECLARED AS LOCAL VARIABLE*****************
Node * Insert( Node ** head, int x )
{
    Node * temp = new Node();
    temp->data  = x;
    temp->link  = NULL;
    if( *head != NULL )
        ;
    temp->link = *head;
    temp       = *head;
}
void Print( Node * head )
{
    //    cout <<"List is: " ;
    //    while(head != NULL){
    Print( head->link );
    cout << head->data << "\t";
    //       head = head->link;
    //    }
    //    cout <<"\n" << endl;
}

int main()
{
    Node * head = NULL;
    int n, x;
    cout << "How many numbers: " << endl;
    cin >> n;
    for( int i = 0; i <= n; i++ )
    {
        cout << "Enter the number" << endl;
        cin >> x;
        Insert( &head, x );
        Print( head );
    }
}
