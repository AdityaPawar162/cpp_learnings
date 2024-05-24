#include <algorithm>
#include <iostream>
#include <vector>

int calculateWeight( int n )
{
    int sum = 0;
    while( n > 0 )
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main()
{
    std::vector<int> arr = { 123, 45, 678, 90, 12, 34 };
    std::sort( arr.begin(), arr.end(), []( int a, int b ) { return calculateWeight( a ) < calculateWeight( b ); } );
    for( int i : arr )
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
