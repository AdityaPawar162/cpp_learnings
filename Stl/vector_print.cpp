#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main()
{
    std::vector<int> numbers;
    std::generate_n( std::back_inserter( numbers ), 10, [n = 0]() mutable { return ++n; } );
    std::ostream_iterator<int> output( std::cout, " " );
    std::copy( numbers.begin(), numbers.end(), output );
    std::cout << '\n';

    return 0;
}