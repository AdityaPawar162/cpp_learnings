/*std::variant is a type-safe replacement for union type*/
#include <iostream>
#include <variant>

int main()
{
    try
    {
        std::variant<std::string, int> v{ 5 }; // v is int, value is 5
        auto val = std::get<int>( v );
        val      = std::get<1>( v );
        std::cout << std::get<int>( v ) << '\n';
        v = "Hello";
        std::cout << std::get<std::string>( v ) << '\n'; // v is string, value is Hello
    }
    catch( const std::bad_variant_access & e )
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}