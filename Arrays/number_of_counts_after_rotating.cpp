#include <iostream>
using namespace std;
// The intution  is that the index of the minimum element in the given array gives the number of times it got rotated
int number_rotated( int arr[], int n )
{
    int min = arr[0], min_index;
    for( int i = 0; i < n; i++ )
    {
        if( min > arr[i] )
        {
            min       = arr[i];
            min_index = i;
        }
    }
    return min_index;
}

int main()
{

    int arr[] = { 15, 18, 2, 3, 6, 12 };
    int N     = sizeof( arr ) / sizeof( arr[0] );
    cout << number_rotated( arr, N );
    return 0;
}
