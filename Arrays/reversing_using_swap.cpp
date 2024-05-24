#include <iostream>
using namespace std;
// EXAMPLE OF SWAP
void reverse( int arr[], int start, int end )
{
    int mid = ( start + end ) / 2;
    for( int i = 0; i < mid; i++ )
    {
        swap( arr[i], arr[end - ( mid - i + 1 )] );
    }
}
int main()
{
    // To reverse an array
    int arr[5] = { 1, 2, 3, 4, 5 };
    int N      = sizeof( arr ) / sizeof( arr[0] );
    reverse( arr, 0, N );
    for( int i = 0; i < N; i++ )
    {
        cout << arr[i];
    }

    return 0;
}
