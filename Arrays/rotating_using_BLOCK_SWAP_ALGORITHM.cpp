/*BLOCK SWAP*/
#include <iostream>
using namespace std;
void swap( int arr[], int s, int f, int d )
{
    for( int i = 0; i < d; i++ )
    {
        int temp   = arr[s + i];
        arr[s + i] = arr[f + i];
        arr[f + i] = temp;
    }
}
void rotate( int arr[], int d, int n )
{
    int i, j;
    i = d;
    j = n - d;
    while( i != j )
    {
        if( i < j )
        {
            swap( arr, d - i, d + j - i, i );
            j = j - i;
        }
        if( j < i )
        {
            swap( arr, d - i, d, j );
            i = i - j;
        }
        swap( arr, d - i, d, i );
    }
}
void printArray( int arr[], int size )
{
    for( int i = 0; i < size; i++ )
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    rotate( arr, 2, 10 );
    printArray( arr, 10 );
    return 0;
}
