#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>

void unordered_multiset()
{
    std::unordered_multiset<std::string> fruits;
    fruits.insert( "apple" );
    fruits.insert( "banana" );
    fruits.insert( "apple" );
    fruits.insert( "orange" );
    fruits.insert( "apple" );
    fruits.insert( "mango" );
    fruits.insert( "banana" );
    const auto appleCount = fruits.count( "apple" );
    std::cout << "Number of apples: " << appleCount << '\n';
    auto [begin, end] = fruits.equal_range(
        "apple" ); // equal_range() is a function which is used to get the range of elements with the same key
    for( auto it = begin; it != end; ++it )
    {
        std::cout << *it << ' ';
    }
    std::cout << '\n';
    auto found = fruits.find( "mango" );
    if( found != std::end( fruits ) )
    {
        std::cout << "Found mango\n";
    }
    else
    {
        std::cout << "Mango not found\n";
    }
    fruits.erase( "apple" );
    std::cout << "Number of apples after erase:" << fruits.count( "apple" ) << '\n';
    std::cout << "Load factor: " << fruits.load_factor() << '\n';
    std::cout << "Bucket count: " << fruits.bucket_count() << '\n';
    fruits.rehash( 50 );
    std::cout << "Bucket count after rehashing: " << fruits.bucket_count() << '\n';
    for( const auto & fruit : fruits )
    {
        std::cout << fruit << " ";
    }
    std::cout << '\n';
}

int main()
{
    unordered_multiset();
    return 0;
}