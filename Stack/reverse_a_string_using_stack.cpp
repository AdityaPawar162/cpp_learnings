#include <cstring>
#include <iostream>
#include <stack>
using namespace std;

void Reverse( char * C, int n )
{
    stack<char> S;
    // loop for push
    for( int i = 0; i < n; i++ )
    {
        S.push( C[i] );
    }
    // loop for making the element to top and pop
    for( int i = 0; i < n; i++ )
    {
        C[i] = S.top();
        // pop
        S.pop();
    }
}

int main()
{
    char C[51];
    cout << "The string is ";
    cin >> C;
    //	cout << "Reverse string is";
    Reverse( C, strlen( C ) );
    cout << C;
}
