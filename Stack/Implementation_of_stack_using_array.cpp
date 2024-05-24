#include <iostream>
using namespace std;
#define MAX_SIZE 101
class stack
{
private:
    int top, A[MAX_SIZE];

public:
    stack()
    {
        top = -1;
    }
    void push( int x )
    {
        //			top ++;
        if( top == MAX_SIZE - 1 )
        {
            cout << "Error:stack overflowed ";
            return;
        }

        A[++top] = x; // INCREMENTING VALUE OF TOP BEFORE ASSIGINIG TO TOP
    }

    void pop()
    {
        if( top == -1 )
        {
            cout << "No elements are present to be deleted";
            return;
        }

        top--;
    }

    int Top()
    {

        return A[top];
    }

    int IsEmpty()
    {
        if( top == -1 )
            return 1;
        return 0;
    }

    void print()
    {
        int i;
        cout << "Stack is :";
        for( i = 0; i <= top; i++ )
            cout << A[i];
        cout << "\n";
    }
};

int main()
{
    stack S;
    S.push( 2 );
    S.print();
    S.push( 4 );
    S.print();
    S.push( 5 );
    S.print();
    S.push( 6 );
    S.print();
    S.pop();
    S.print();
    cout << "The element at top is " << S.Top();
    cout << "To check the element is empty " << S.IsEmpty();
}
