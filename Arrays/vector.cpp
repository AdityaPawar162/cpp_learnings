#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<char> v( 10 );
    int i;
    for( i = 0; i < 5; i++ )
    {
        v[i] = i + 'A';
    }
    for( int i = 0; i < v.size(); i++ )
    {
        cout << v[i] << " ";
    }
    for( i = 0; i < 5; i++ )
    {
        v.push_back( i + 10 + 'A' );
    }
    cout << "Size of the element" << v.size();

    return 0;
}
