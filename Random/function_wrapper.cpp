/*std::function is a general purpose function wrapper
  Can store and invoke and target that can be invoked with operator() syntax*/
#include <functional>
#include <iostream>

int Square( int x )
{
    return x * x;
}
int Add( int x, int y )
{
    return x + y;
}

int Subtract( int x, int y )
{
    return x - y;
}

struct Max
{
    int operator()( int x, int y ) const
    {
        return x > y ? x : y;
    }
};

int Operation( int x, int y, std::function<int( int, int )> callback )
{
    return callback( x, y );
}

int main()
{
    try
    {
        std::function<int( int )> f1 = Square;
        std::cout << f1( 5 ) << '\n';
        Max m;
        std::function<int( int, int )> f2 = m;
        std::cout << f2( 10, 20 ) << '\n';
        std::function<int( int, int )> f3 = Add;
        std::cout << Operation( 10, 20, f3 ) << '\n';
        std::function<int( int, int )> f4 = Subtract;
        std::cout << Operation( 10, 20, f4 ) << '\n';
        std::cout << Operation( 10, 20, []( int x, int y ) { return x * y; } ) << '\n';
    }
    catch( const std::exception & e )
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}