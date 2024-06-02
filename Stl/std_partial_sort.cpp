#include <algorithm>
#include <array>
#include <iostream>

// Rearranges elements such that the range [first, middle) contains the sorted middle − first smallest elements in the
// range [first, last).

int main()
{
    std::vector<int> v{ 3, 1, 4, 1, 5, 9 };
    std::partial_sort( std::begin( v ), std::begin( v ) + 3, std::end( v ) );
    for( const auto & i : v )
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';

    return 0;
}