#include <algorithm>
#include <iostream>
#include <vector>

/*
Explanation
1.Initial Vector: We have a vector v with elements { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 }.
2.nth Element: We want to find the median element, which is the middle element of the sorted vector. For a vector of
size 11, the median is at position 5 (0-indexed). 3.Calling std::nth_element: The call std::nth_element(v.begin(), nth,
v.end()) rearranges the elements in the vector such that the element at the nth position is the element that would be
there if the vector were fully sorted. Elements before nth are less than or equal to the median, and elements after nth
are greater than or equal to the median.

Use Cases
1.Finding the k-th Smallest/Largest Element: Efficiently find the k-th smallest or largest element without sorting the
entire array. 2.Partitioning: Partition elements into two groups based on a pivot value. 3.Median Calculation: Quickly
find the median value in a dataset.

*/

int main()
{
    std::vector<int> v{ 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };

    // Find the median (5th element in a 0-indexed array)
    auto nth = std::begin( v ) + std::size( v ) / 2; // Middle element
    std::nth_element( std::begin( v ), nth, std::end( v ) );

    std::cout << "The median is " << *nth << '\n';

    for( auto it = std::begin( v ); it != std::end( v ); ++it )
    {
        std::cout << *it << ' ';
    }

    std::cout << '\n';
}