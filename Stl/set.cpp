/*
set - implemented as a binary tree,values are stored in sorted order.
*/

#include <iostream>
#include <set>
#include <vector>

void Set()
{
    std::set<int, std::greater<int>> s{ 8, 2, 0, 9, 5 };

    s.insert( 1 );
    s.insert( 2 );

    auto itr = s.begin();
    itr      = s.find( 4 );
    if( itr != s.end() )
    {
        std::cout << "Element found" << std::endl;
    }
    else
    {
        std::cout << "Not\n";
    }
}

void Set_Operations()
{
    std::set<int> numbers{ 5, 3, 8, 1, 4 };
    auto [position, wasinserted] = numbers.insert( 6 );
    if( wasinserted )
    {
        std::cout << "6 was inserted at position " << *position << '\n';
    }
    else
    {
        std::cout << "6 was not inserted\n";
    }
    auto result = numbers.emplace( 5 );
    // std::cout << result.second  << '\n';
    if( !result.second )
    {
        std::cout << "5 was not inserted because it is already in the set\n";
    }
    if( numbers.find( 8 ) != numbers.end() )
    {
        std::cout << "8 was found\n";
    }
    numbers.erase( 1 );
    std::cout << "Elements in set:" << '\n';
    for( const auto & it : numbers )
    {
        std::cout << it << " ";
    }
    std::cout << '\n';
    std::set<int> moreNumbers{ 9, 7, 2 };
    numbers.merge( moreNumbers );
    std::cout << "After merging:" << '\n';
    for( const auto & it : numbers )
    {
        std::cout << it << " ";
    }
    std::cout << '\n';
    if( numbers.count( 2 ) )
    {
        std::cout << "2 is in the set\n";
    }
    else
    {
        std::cout << "2 is not in the set\n";
    }
    numbers.clear();

    std::set<std::string, bool ( * )( const std::string &, const std::string & )> caseInsensitiveSet{
        []( const std::string & lhs, const std::string & rhs )
        {
            return std::lexicographical_compare(
                std::begin( lhs ), std::end( lhs ), std::begin( rhs ), std::end( rhs ),
                []( char c1, char c2 ) { return std::tolower( c1 ) < std::tolower( c2 ); } );
        }
    };

    caseInsensitiveSet.insert( "hello" );
    caseInsensitiveSet.insert( "world" );
    if( !caseInsensitiveSet.insert( "Hello" ).second )
    {
        std::cout << "Duplicate insertion was detected\n";
    }
}

int main()
{
    // Set();
    Set_Operations();

    return 0;
}