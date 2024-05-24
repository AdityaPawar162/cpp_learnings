#include <algorithm>
#include <array>
#include <iostream>

void Array()
{
    std::array<int, 5> arr{ 5, 1, 9, 8 };
    for( auto it : arr )
    {
        std::cout << it << " ";
    }
    std::cout << '\n';

    std::cout << "arr.data " << static_cast<void *>( arr.data() )
              << '\n'; // Give the pointer to the underlying data to the data array
}

struct Point
{
    int x{ 0 };
    int y{ 0 };
};

constexpr int sumArray( const std::array<int, 5> & arr )
{
    int sum{ 0 };
    for( const auto & it : arr )
    {
        sum += it;
    }
    return sum;
}
/*
This example highlights the features and advantages of std::array, including its fixed-size nature,
compatibility with modern C++ features like structured bindings, and its utility in compile-time
computations.
*/

void Array_Operations()
{
    std::array<int, 5> numbers{ 5, 3, 8, 1, 4 };
    std::array<Point, 3> points{ { Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 } } };
    for( const auto & [x, y] : points )
    {
        std::cout << x << " " << y << '\n';
    }
    constexpr std::array<int, 5> constNumbers{ 1, 2, 3, 4, 5 };

    constexpr int totalSum = sumArray( constNumbers );
    std::cout << "\n Compile time sum of the array is " << totalSum << '\n';
    std::sort( std::begin( numbers ), std::end( numbers ) );
    std::cout << "\n Sorted numbers are: ";
    for( const auto & it : numbers )
    {
        std::cout << it << " ";
    }
    std::cout << '\n';
    int searchValue{ 3 };
    if( std::find( std::begin( numbers ), std::end( numbers ), searchValue ) != std::end( numbers ) )
    {
        std::cout << "Found " << searchValue << '\n';
    }
    else
    {
        std::cout << "Not found " << searchValue << '\n';
    }
}

int main()
{
    // Array();
    Array_Operations();

    return 0;
}