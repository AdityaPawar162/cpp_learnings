/*A fold expression reduces a parameter pack over a binary operator*/
// The syntax for a fold expression is:
// ( pack op ... ) :unary right fold
// ( ... op pack ) :unary left fold
// ( pack op ... op init ) :binary right fold
// ( init op ... op pack ) :binary left fold

#include <iostream>

template<typename... Args>
auto Sum( Args... args )
{
    // return (args + ...); // Unary right fold
    return ( ... + args ); // Unary left fold
}

template<typename... Args>
auto Sum2( Args... args )
{
    return ( 0 + ... + args ); // Binary right fold
}

/*
 * Unary right fold
 * Sum2(1,2,3,4,5)
 * (1 +(2 +(3 +(4 +(5 + 0)))
 *
 * Unary left fold
 * Sum(1,2,3,4,5)
 * ((((1 + 2) + 3) + 4) + 5)
 *
 * Binary right fold
 * Sum2(1,2,3,4,5)
 * (1 +(2 +(3 +(4 +(5 + 0))
 *
 * Binary left fold
 * Sum2(1,2,3,4,5)
 * ((((0 + 1) + 2) + 3) + 4) + 5
 */

int main()
{
    auto result = Sum( 1, 2, 3, 4, 5 ); // Unary left fold
    // auto result = Sum2(); // Works with Binary right fold but not with Unary right fold
    std::cout << "Sum: " << result << "\n";
}