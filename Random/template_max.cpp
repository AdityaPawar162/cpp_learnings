#include <iostream>
using namespace std;
template<class T>
void display( T x )
{
    cout << x << endl;
}
int main()
{
    display( "Hello" );
    display( 10 );
    display( 10.0001 );

    return 0;
}
