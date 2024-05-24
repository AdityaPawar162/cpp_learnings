#include <limits.h>
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node * next;
};

class Stack
{
private:
    Node * head;

public:
    Stack() : head( nullptr ) {} // Constructor to initialize head to nullptr

    void Push( int x )
    {
        Node * newNode = new Node;
        newNode->data  = x;
        newNode->next  = head;
        head           = newNode;
    }

    void Pop()
    {
        if( head == nullptr )
            return; // Check if stack is empty
        Node * temp = head;
        head        = head->next;
        delete temp; // Deallocate memory for popped node
    }

    int Top()
    {
        if( head == nullptr )
            return INT_MIN; // Assuming INT_MIN represents empty stack
        return head->data;
    }

    bool IsEmpty()
    {
        return head == nullptr;
    }

    void Print()
    {
        Node * temp = head;
        cout << "The stack: ";
        while( temp != nullptr )
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack s;
    s.Push( 2 );
    s.Print();
    s.Push( 4 );
    s.Print();
    s.Push( 6 );
    s.Print();
    s.Pop();
    s.Print();
    cout << "Is empty condition: " << s.IsEmpty() << endl;
    cout << "Value at top: " << s.Top() << endl;

    return 0;
}
