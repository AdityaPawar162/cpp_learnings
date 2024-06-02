#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<double> prices{ 5.99, 10.49, 20.89, 25.55, 30.10 };
    if( std::is_sorted( std::begin( prices ), std::end( prices ) ) )
    {
        std::cout << "Prices are sorted\n";
    }
    else
    {
        std::cout << "Prices are not sorted\n";
    }

    for( const auto & price : prices )
    {
        std::cout << price << ' ';
    }
    std::cout << '\n';
    auto partition_point = std::partition_point(
        std::begin( prices ), std::end( prices ), []( double price_value = 20.0 ) { return price_value < 20.0; } );
    std::cout << "Partition point is at index: " << std::distance( std::begin( prices ), partition_point ) << '\n';
    for( const auto & price : prices )
    {
        std::cout << price << ' ';
    }
    std::cout << '\n';
    if( std::is_partitioned( std::begin( prices ), std::end( prices ), []( double prices ) { return prices < 20.0; } ) )
    {
        std::cout << "Prices are partitioned with prices less than 20.0\n";
    }
    else
    {
        std::cout << "Prices are not partitioned with prices less than 20.0\n";
    }

    std::vector<double> permutated_prices{ 25.55, 5.99, 30.10, 10.49, 20.89 };
    if( std::is_permutation( std::begin( prices ), std::end( prices ), std::begin( permutated_prices ) ) )
    {
        std::cout << "Prices are permutated\n";
    }
    else
    {
        std::cout << "Prices are not permutated\n";
    }
}