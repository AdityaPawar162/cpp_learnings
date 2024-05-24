#include <iostream>
using namespace std;

void cyclic_rotate( int arr[], int n )
{
    int last = arr[n - 1], i;
    for( i = n - 1; i > 0; i-- )
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = last;
    /*Another way
    arr[i] = 0
    while(i!=j){
        swap(arr[i],arr[j];
        i++
    }

    */
}
int main()
{
    int arr[] = { 1, 2, 3, 4, 5 }, n;
    n         = sizeof( arr ) / sizeof( arr[0] );
    cout << "Given array is: ";
    for( int i = 0; i < n; i++ )
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cyclic_rotate( arr, n );
    cout << "Cyclic rotated array is: ";
    for( int i = 0; i < n; i++ )
    {
        cout << arr[i] << " ";
    }

    return 0;
}
