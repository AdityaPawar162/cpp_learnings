// List is implemented as a double linked list, whereas forward list only as a linked list
#include <algorithm>
#include <forward_list>
#include <iostream>
#include <list>

void List()
{
    std::list<int> coll;
    for( int i = 0; i < 5; i++ )
    {
        coll.push_back( i * 10 );
    }

    auto itr = coll.begin();
    while( itr != coll.end() )
    {
        std::cout << *itr++ << '\n';
    }
}
void Dispaly( const std::list<int> & lst )
{
    for( const auto & it : lst )
    {
        std::cout << it << " ";
    }
    std::cout << '\n';
}

void List_Operations()
{
    std::list<int> numbers{ 5, 1, 8, 7 };
    std::cout << "Numbers in reverse order: ";
    for( auto itr = numbers.rbegin(); itr != numbers.rend(); ++itr )
    {
        std::cout << *itr << " ";
    }
    std::cout << '\n';
    auto pos = std::find( std::begin( numbers ), std::end( numbers ), 8 );
    numbers.insert( pos, 2112 );
    std::cout << "Numbers after inserting 2112: ";
    Dispaly( numbers );
    numbers.sort();
    std::list<int> more_numbers{ 10, 20, 30 };
    numbers.merge( more_numbers );
    std::cout << "Numbers after sorting and merging: ";
    Dispaly( numbers );
    std::list<int> additional_numbers{ 100, 200, 300 };
    numbers.splice( std::begin( numbers ), additional_numbers );
    std::cout << "After splicing: ";
    Dispaly( numbers );
    numbers.remove_if( []( int x ) { return x % 2 == 0; } );
    std::cout << "After removing even numbers: ";
    Dispaly( numbers );
}

void Forward_list()
{
    std::forward_list<int> coll;
    for( int i = 0; i < 5; i++ )
    {
        coll.push_front( i * 10 );
    }
    for( auto x : coll )
    {
        std::cout << x << '\n';
    }
    coll.insert_after( coll.begin(), 10 );
}

int main()
{
    Forward_list();
    List_Operations();
    return 0;
}