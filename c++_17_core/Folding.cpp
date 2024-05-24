#include <iostream>

auto Sum()
{
    return 0;
}

template<typename T, typename... Args>
auto Sum( T a, Args... args )
{
    return a + Sum( args... );
}
/*
 * Sum(1,2,3,4,5)
 * return 1 + Sum(2,3,4,5)
 * return 2 + Sum(3,4,5)
 * return 3 + Sum(4,5)
 * return 4 + Sum(5)
 * return 5 + Sum()
 * return 5 + 0
 *
 */

int main()
{
    auto result = Sum( 1, 2, 3, 4, 5 );
    std::cout << "Sum: " << result << "\n";
}