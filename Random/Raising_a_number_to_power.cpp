#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    int psequence = x, product = 1;
    while( n > 0 )
    {
        if( n % 2 == 1 )
        {
            product = product * psequence;
        }
        n /= 2;
        psequence = psequence * psequence;
    }
    cout << product;
    return 0;
}
