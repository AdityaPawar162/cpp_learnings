#include <bits/stdc++.h>
using namespace std;
int main()
{
    list<int> lst;
    for( int i = 0; i < 5; i++ )
    {
        lst.push_back( i );
    }
    cout << ".....Iterating through the list.." << endl;
    list<int>::const_iterator it;
    for( it = lst.begin(); it != lst.end(); it++ )
    {
        cout << *it << ' ';
    }
    cout << endl;
    return 0;
}
