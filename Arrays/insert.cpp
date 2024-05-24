// To insert the element at the end of the array
#include <iostream>
using namespace std;
int insert( int arr[], int n, int element, int capacity )
{
    if( n > capacity )
    {
        return 0;
    }

    arr[n] = element;

    return n + 1;
}
void print( int arr[], int n )
{
    for( int i = 0; i < n; i++ )
    {
        cout << arr[i];
    }
    cout << "\n";
}
int main()
{
    int arr[6] = { 1, 2, 3, 4, 5 };
    int n      = sizeof( arr ) / sizeof( arr[0] );
    cout << "Array before insertion" << endl;
    print( arr, n );
    int result = insert( arr, n, 7, 6 );
    print( arr, n );
    return 0;
}
