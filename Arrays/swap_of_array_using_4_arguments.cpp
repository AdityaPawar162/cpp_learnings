#include <iostream>

using namespace std;

void swap( int arr[], int start, int end, int p, int q )
{
    int temp       = arr[start + p];
    arr[start + p] = arr[end + q];
    arr[end + q]   = temp;
}

int main()
{
    int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    swap( arr, 0, 2, 3, 5 );
    int n = sizeof( arr ) / sizeof( arr[0] );
    for( int i = 0; i < n; i++ )
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
