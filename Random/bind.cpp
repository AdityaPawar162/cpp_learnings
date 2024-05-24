#include <functional>
#include <iostream>

int Subtract( int x, int y )
{
    return x - y;
}

struct GreaterThan
{
    bool operator()( int x, int y ) const
    {
        return x > y;
    }
};

int Operation( int x, int y, std::function<int( int, int )> callback )
{
    return callback( x, y );
}

int Accumulate( int x, int y, int z )
{
    return x + y + z;
}

int main()
{
    // std::function<int(int,int)> f = std::bind(Subtract,std::placeholders::_1,std::placeholders::_2);
    // std::cout << f(10, 20) << '\n';
    auto f  = std::bind( Subtract, std::placeholders::_1, 5 );
    auto f2 = []( int x ) { return Subtract( x, 5 ); }; // same as above
    std::cout << f( 10 ) << " " << f2( 2 ) << '\n';

    auto gt = std::bind( GreaterThan{}, std::placeholders::_2, std::placeholders::_1 );
    std::cout << gt( 10, 20 ) << '\n';

    auto acc = std::bind( Accumulate, std::placeholders::_1, std::placeholders::_2, 0 );
    std::cout << acc( 10, 20 ) << '\n';

    std::cout << Operation( 8, 5, acc ) << '\n'; // accumulate passed as callback  to Operation function
}