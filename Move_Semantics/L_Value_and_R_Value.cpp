#include <iostream>

// Returns r-value
int Add( int x, int y )
{
    return x + y;
}

// Returns l-value
int & Transform( int & x )
{
    x *= x;
    return x;
}

void Print( [[maybe_unused]] int & x )
{
    std::cout << "Print(int&)" << std::endl;
}

void Print( [[maybe_unused]] const int & x )
{
    std::cout << "Print(const int&)" << std::endl;
}

void Print( [[maybe_unused]] int && x )
{
    std::cout << "Print(int&&)" << std::endl;
}

int main()
{
    int x = 10;
    Print( x ); // Print(int&)

    Print( 10 ); // Print(int&&)

    return 0;
}
