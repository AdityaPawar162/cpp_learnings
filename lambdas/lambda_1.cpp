#include <iostream>

int main()
{
    auto fn = []() { std::cout << "welcome" << std::endl; };

    fn();

    // Generic lambdas
    auto sum = []( auto x, auto y ) noexcept { return x + y; };
    std::cout << sum( 1.2, 2 ) << std::endl;

    return 0;
}