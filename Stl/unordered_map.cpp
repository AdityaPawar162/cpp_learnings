/*
 std::unordered_set stores values that act as keys for hashing, iterators are constant
*/
#include <iostream>
#include <unordered_map>

void unordered_map()
{
    std::unordered_map<std::string, std::string> coll;
    coll["Batman"]   = "Bruce Wayne";
    coll["Superman"] = "Clark Kent";
    coll["Hulk"]     = "Bruce Banner";
    for( const auto & x : coll )
    {
        std::cout << "Bucket #: " << coll.bucket( x.first ) << " contains " << x.first << '\n';
    }

    std::cout << "Bucket count " << coll.bucket_count() << '\n';
    std::cout << "Number of elements " << coll.size() << '\n';
    std::cout << "Load Factor " << coll.load_factor()
              << '\n'; // Load factor is elements / number of capacity of hash table
}

void displaymap( std::unordered_map<std::string, int> & map )
{

    for( const auto & [key, value] : map )
    {
        std::cout << key << ": " << value << '\n';
    }
}

void unordered_map_operations()
{
    std::unordered_map<std::string, int> ageMap;
    ageMap["Lisa"]   = 28;
    ageMap["Corbin"] = 25;
    ageMap["Aaron"]  = 30;
    std::cout << "Corbin's age: " << ageMap["Corbin"] << '\n';
    if( ageMap.find( "Daisy" ) != std::end( ageMap ) )
    {
        std::cout << "Daisy's age: " << ageMap["Daisy"] << '\n';
    }
    else
    {
        std::cout << "Daisy not found \n";
    }
    ageMap["Lisa"] = 29;
    displaymap( ageMap );
    std::cout << "Load Factor: " << ageMap.load_factor() << '\n';
    std::cout << "Bucket count: " << ageMap.bucket_count() << '\n';
    ageMap.rehash( 50 );
    std::cout << "Bucket count after rehasing:" << ageMap.bucket_count() << '\n';
    ageMap.clear();
    displaymap( ageMap );
}

int main()
{
    unordered_map_operations();
    return 0;
}
