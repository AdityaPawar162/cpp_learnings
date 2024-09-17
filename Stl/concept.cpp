#include <concepts>
#include <iostream>
#include <type_traits>

struct NotPrintable
{
    int foo{ 0 };
    int bar{ 0 };
};

template<typename T>
concept Printable = requires( T t )
{
    // Requires that t can be printed to std::cout
    std::cout << t;
};

template<
    typename T,
    typename
    = typename std::enable_if<std::is_same<decltype( std::cout << std::declval<T>() ), std::ostream &>::value>::type>
void printValueSFINAE( const T & value )
{
    std::cout << "Value: " << value << "\n";
}
template<Printable T>
void printaValue( const T & value )
{
    std::cout << "Value: " << value << '\n';
}

int main()
{
    const int num = 42;
    const NotPrintable np;
    const std::string str_1{ "Hello, Concepts!" };

    printValueSFINAE( num );
    printValueSFINAE( str_1 );
    printValueSFINAE( np );


    printaValue( num );
}