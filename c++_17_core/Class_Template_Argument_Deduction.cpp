#include <iostream>
#include <string>
#include <vector>

template<typename T>
class Data
{
public:
    Data( const T & ) {}
};
Data( const char * )->Data<std::string>; // Deduction guide

int main()
{
    Data data1( 10 );   // T is deduced as int
    Data d2{ 8.2f };    // T is explicitly specified as float
    Data d3{ "Hello" }; // T is deduced as const char[6] but the deduction guide specifies that it should be std::string

    return 0;
}