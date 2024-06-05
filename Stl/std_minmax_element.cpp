#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> scores = { 85, 93, 78, 90, 96, 82 };
    auto max_element        = std::max_element( std::begin( scores ), std::end( scores ) );
    if( max_element != std::end( scores ) )
    {
        std::cout << "Maximum elements is " << *max_element << '\n';
    }
    auto min_element = std::min_element( std::begin( scores ), std::end( scores ) );
    if( min_element != std::end( scores ) )
    {
        std::cout << "Minmum element is " << *min_element << '\n';
    }

    auto [minelement, maxelement] = std::minmax_element( std::begin( scores ), std::end( scores ) );
    if( minelement != std::end( scores ) && maxelement != std::end( scores ) )
    {
        std::cout << "Minmum and Maximum element is " << *minelement << "and " << *maxelement << '\n';
    }

    std::vector<double> productPrices = { 99.99, 79.99, 49.99, 59.99, 89.99 };
    // Find the minimum and maximum prices
    auto minmaxPrices = std::minmax_element( productPrices.begin(), productPrices.end() );
    if( minmaxPrices.first != productPrices.end() && minmaxPrices.second != productPrices.end() )
    {
        std::cout << "The cheapest and priciest products cost: $" << *minmaxPrices.first << " and $"
                  << *minmaxPrices.second << ", respectively.\n";
    }
    return 0;
}