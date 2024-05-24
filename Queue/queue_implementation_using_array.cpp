#include <cstring>
#include <iostream>
using namespace std;
int front = -1;
int rear  = -1;
int A[10];
bool IsEmpty()
{
    if( front == -1 && rear == -1 )
        return true;
    return false;
}
// bool IfFull(){
//	if(rear == A.length())return true;
//	return false;
// }
void Enqueue( int x )
{
    //	if(IsFull())return
    if( IsEmpty() )
    {
        front = 0;
        rear  = front;
    }
    else
    {
        rear = rear + 1;
    }
    A[rear] = x;
}
void Dequeue()
{
    if( IsEmpty() )
        return;
    else if( front == rear )
    {
        front = -1;
        rear  = front;
    }
    else
        front = front + 1;
}
int main()
{
    Enqueue( 2 );
    Enqueue( 4 );
    Dequeue();
    cout << A[0] << A[1];
}
