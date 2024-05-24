#include <algorithm>
#include <iostream>
#include <string>

void string_Operations()
{
    std::string s{ "Hello, C++ World!" };
    std::cout << "Size: " << s.size() << '\n';
    std::cout << "First Char" << s[0] << '\n';
    std::string greet{ "Hello" };
    std::string target{ "World" };
    std::string combined = greet + ", " + target + "!";
    std::cout << "Combined: " << combined << '\n';
    if( s.find( "C++" ) != std::string::npos )
    {
        std::cout << "Found C++\n";
    }
    std::transform(
        std::begin( s ), std::end( s ), std::begin( s ), []( unsigned char c ) { return std::toupper( c ); } );
    std::cout << "Upper Case: " << s << '\n';
    std::transform(
        std::begin( s ), std::end( s ), std::begin( s ), []( unsigned char c ) { return std::tolower( c ); } );
    std::cout << "Lower Case: " << s << '\n';
    s.erase( std::remove( std::begin( s ), std::end( s ), ' ' ), std::end( s ) );
    std::cout << "After removing spaces: " << s << '\n';
    std::string first{ "apple" };
    std::string second{ "banana" };
    if( first < second )
    {
        std::cout << "apple is less than banana\n";
    }
    else
    {
        std::cout << "banana is less than apple\n";
    }

    int number{ 2112 };
    std::string numberStr = std::to_string( number );
    std::cout << "Number as string: " << numberStr << '\n';
    int convertedBack = std::stoi( numberStr );
    std::cout << "Converted back to int: " << convertedBack << '\n';
}

int main()
{
    string_Operations();

    return 0;
}