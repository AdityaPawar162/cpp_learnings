/* Implemented as binary tree,stores a pair that contains a key and value, elements are stored in sorted order based on
 a key, elements are stored in sorted order based on a key Map is not for handling duplicate keys but multimap is.
*/

#include <algorithm>
#include <iostream>
#include <map>
#include <string>

void Map()
{

    std::map<int, std::string> m{
        { 1, "Superman" }, { 2, "Batman" }, { 3, "Green Lantern" } // First way of inserting values in map
    };

    m.insert( std::pair<int, std::string>( 8, "Aquaman" ) ); // Second way of inserting value in map

    m.insert( std::make_pair( 6, "Wonder woman" ) ); // Third way of inserting value in map

    m[0] = "Flash"; // Fourth way of inserting values in map

    for( auto const & x : m )
    {
        std::cout << x.first << " " << x.second << std::endl;
    }

    auto itr = m.find( 1 );
    std::cout << itr->second << std::endl; // Prints the value present at the key specified to itr
}

void Map_Operations()
{
    std::map<int, std::string> m{ { 1, "Superman" }, { 2, "Batman" }, { 3, "Green Lantern" } };

    auto [position, wasinserted] = m.insert( std::make_pair(
        8,
        "Aquaman" ) ); // Inserting a value in map using insert function. Here auto [position, wasinserted] is a structured
                       // binding which is used to store the return value of insert function in position and wasinserted.
    if( wasinserted )
    {
        std::cout << "[structured binding] 8 was inserted at position " << position->first << '\n';
    }
    else
    {
        std::cout << "[structured binding] 8 was not inserted\n";
    }
    m[4] = "Flash";                          // Inserting a value in map using [] operator
    m.insert_or_assign( 5, "Wonder woman" ); // Inserting a value in map using insert_or_assign function
    if( m.key_comp()( 1, 2 ) )               // key_comp() is a function which is used to compare the keys of the map
    {
        std::cout << "[key_comp] 1 is less than 2\n";
    }
    if( m.get_allocator()
        == m.get_allocator() ) // get_allocator() is a function which is used to get the allocator of the map
    {
        std::cout << "[get_allocator] Both allocators are same\n";
    }
    if( m.value_comp()(
            *m.begin(), *m.rbegin() ) ) // value_comp() is a function which is used to compare the values of the map
    {
        std::cout << "[value_comp] First value is less than last value\n";
    }
    if( m.find( 10 ) != m.end() ) // find() is a function which is used to find the value in the map
    {
        std::cout << "[find] 10 was found\n";
    }
    else
    {
        std::cout << "[find] 10 was not found\n";
    }
    for( const auto & [value, name] : m ) // Iterating through the map using structured binding
    {
        std::cout << "[For_Loop] " << value << " " << name << '\n';
    }
    if( m.count( 2 ) ) // count() is a function which is used to count the number of elements in the map
    {
        std::cout << "[count] 2 was found\n";
    }
    else
    {
        std::cout << "[count] 2 was not found\n";
    }
    if( m.equal_range( 2 ).first
        != m.end() ) // equal_range() is a function which is used to get the range of elements with the same key
    {
        std::cout << "[equal_range] 2 was found\n";
    }
    else
    {
        std::cout << "[equal_range] 2 was not found\n";
    }

    std::map<int, std::string, bool ( * )( const int &, const int & )> customOrderMap{
        []( const int & lhs, const int & rhs ) { return lhs > rhs; }
    }; // Creating a map with custom comparator
    customOrderMap[1] = "Superman";
    customOrderMap[2] = "Batman";
    customOrderMap[3] = "Green Lantern";
    for( const auto & [value, name] : customOrderMap )
    {
        std::cout << "[Custom_Comparator] " << value << " " << name << '\n';
    }

    [[maybe_unused]] auto result = m.emplace( 5, "Wonder" );
}

int main()
{
    // Map();
    Map_Operations();

    return 0;
}