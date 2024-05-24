#include <bits/stdc++.h>
using namespace std;

int superPow( int a, vector<int> & b )
{ //,
    int num = 0;
    for( auto x : b )
    {
        num = x + num * 10;
    }
    return pow( a, num );
    long long product     = 1;
    long long presequence = a;
    while( num > 0 )
    {
        if( num % 2 == 0 )
            product = product * presequence;
        num /= 2;
        presequence = presequence * presequence;
    }
    return product;
}

int main()
{

    vector<int> arr = { 1, 0 };
    cout << superPow( 2, arr );

    return 0;
}
