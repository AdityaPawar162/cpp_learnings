#include <iostream>
#include <map>
#include <string>

void multimap()
{
    
    std::multimap<std::string, int> grades;
    grades.insert( { "John", 85 } );
    grades.insert( { "Corbin", 65 } );
    grades.insert( { "Regan", 92 } );
    grades.insert( { "John", 90 } );

    for( const auto & [name, value] : grades )
    {
        std::cout << name << " scored " << value << '\n';
    }
    std::cout << '\n';
    std::cout << "John's grades count: " << grades.count( "John" ) << '\n';

    auto ext = grades.extract( "John" );
    std::cout << "[extract] extracted " << ext.key() << '\n';

    auto [begin, end] = grades.equal_range( "John" );
    for( auto it = begin; it != end; ++it )
    {
        std::cout << it->first << " scored " << it->second << '\n';
    }
    std::cout << '\n';
    std::multimap<std::string, int, std::greater<>> reverseGrades{
        { "Mandy", 85 }, { "Mandy", 82 }, { "Aaron", 90 }, { "Dan", 76 }
    };
    for( const auto & [name, score] : reverseGrades )
    {
        std::cout << "[custom comparator] " << name << " scored " << score << '\n';
    }
    std::cout << '\n';
}

int main()
{
    multimap();

    return 0;
}