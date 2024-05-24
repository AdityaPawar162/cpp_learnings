#include <iostream>
#include <string>
#include <unordered_map>

void multimap_operations()
{
    std::unordered_multimap<std::string, int> grades;
    grades.insert( { "Lisa", 85 } );
    grades.insert( { "Corbin", 92 } );
    grades.insert( { "Lisa", 89 } );
    grades.insert( { "Corbin", 88 } );
    grades.insert( { "Aaron", 76 } );
    grades.insert( { "Regan", 91 } );
    size_t lisaCount = grades.count( "Lisa" );

    std::cout << "Number of grade entries for Lisa: " << lisaCount << '\n';
    auto [begin, end] = grades.equal_range( "Lisa" );
    for( auto & it = begin; it != end; ++it )
    {
        std::cout << it->first << " : " << it->second << '\n';
    }
    auto lisa = grades.find( "Lisa" );
    if( lisa != grades.end() )
    {
        lisa->second = 90; // change Lisa's grade to 90
    }
    grades.erase( "Corbin" );
    std::cout << "Number of grade entries for Lisa: " << grades.count( "Lisa" ) << '\n';

    for( const auto & entry : grades )
    {
        std::cout << entry.first << " received grade: " << entry.second << '\n';
    }
}

int main()
{
    multimap_operations();
    return 0;
}