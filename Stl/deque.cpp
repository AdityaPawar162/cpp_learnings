#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>

void Deque()
{
    std::deque<int> coll;
    for( int i = 0; i < 5; i++ )
    {
        coll.push_back( i * 10 );
    }

    for( int i = 0; i < 5; i++ )
    {
        coll.push_front( i * 10 );
    }
    coll[0]  = 100;
    auto itr = coll.begin();
    while( itr != coll.end() )
    {
        std::cout << *itr++ << '\n';
    }

    coll.insert( coll.begin(), 70 );
    coll.erase( coll.end() - 4 );
    coll.pop_back();
    coll.pop_front();
}

void procesInSlidingWindow( const std::deque<int> & data, size_t windowSize )
{
    for( size_t i = 0; i <= data.size() - windowSize; ++i )
    {
        int sum = 0;
        for( size_t j = i; j < i + windowSize; ++j )
        {
            sum += data[j];
        }
        std::cout << "Average of window starting at index " << i << ": " << static_cast<double>( sum ) / windowSize
                  << "\n";
    }
}

void Deque_operations()
{
    std::deque<int> numbers;
    for( int i = 0; i < 5; i++ )
    {
        numbers.push_back( i * 10 );
    }
    std::cout << "Numbers  in deque: ";
    for( auto num : numbers )
    {
        std::cout << num << " ";
    }
    std::cout << '\n';
    numbers.pop_back();
    numbers.pop_front();
    std::cout << "Numbers after pop_back and pop_front: ";
    for( auto num : numbers )
    {
        std::cout << num << " ";
    }
    std::cout << '\n';
    procesInSlidingWindow( numbers, 3 );
    std::transform(
        std::begin( numbers ), std::end( numbers ), std::begin( numbers ), []( int val ) { return val * 2; } );
    std::cout << "Numbers after Doubling: ";
    for( auto num : numbers )
    {
        std::cout << num << " ";
    }
    std::cout << '\n';
}

int main()
{

    // Deque();

    Deque_operations();
    return 0;
}
