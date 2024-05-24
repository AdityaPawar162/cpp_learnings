#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[] = { 1, 10, 29, 67, 57, 12, 32 };
    vector<int> v( a, a + 7 );
    make_heap( v.begin(), v.end() );
    cout << ".....After making Heap......" << endl;
    for( unsigned i = 0; i < v.size(); i++ )
    {
        cout << v[i] << " ";
    }
    sort_heap( v.begin(), v.end() );
    cout << ".......After sorting Heap......." << endl;
    for( unsigned i = 0; i < v.size(); i++ )
    {
        cout << v[i] << " ";
    }
    v.push_back( 100 );
    push_heap( v.begin(), v.end() );
    cout << ".....After pushing and sorting the heap with 100 as the new element......" << endl;
    sort_heap( v.begin(), v.end() );
    for( unsigned i = 0; i < v.size(); i++ )
    {
        cout << v[i] << " ";
    }
    return 0;
}
