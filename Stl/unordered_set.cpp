/*
 std::unordered_set stores values that act as keys for hashing, iterators are constant
*/
#include <iostream>
#include <unordered_set>

void unordered_set()
{
    std::unordered_multiset<std::string> coll;
    coll.insert( "Hulk" );
    coll.insert( "Batman" );
    coll.insert( "Green Lantern" );
    coll.insert( "The Flash" );
    coll.insert( "Wonder woman" );
    coll.insert( "Iron man" );
    coll.insert( "Wolverine" );
    coll.insert( "Dr. Strange" );
    coll.insert( "Hawkman" );
    for( const auto & x : coll )
    {
        std::cout << "Bucket #: " << coll.bucket( x ) << " contains " << x << '\n';
    }

    std::cout << "Bucket count " << coll.bucket_count() << '\n';
    std::cout << "Number of elements " << coll.size() << '\n';
    std::cout << "Load Factor " << coll.load_factor()
              << '\n'; // Load factor is elements / number of capacity of hash table
}
int main()
{
    unordered_set();
    return 0;
}
