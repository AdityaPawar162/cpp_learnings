#include <iostream>
#include <unordered_set>
#include <vector>

class Number
{
public:
    Number( [[maybe_unused]] int value )
    {
        std::cout << "Parameterized ctor\n";
    }
    Number( const Number & )
    {
        std::cout << "Copy ctor\n";
    }
    Number( Number && )
    {
        std::cout << "Move ctor\n";
    }
};

void Foo( [[maybe_unused]] Number n )
{
    std::cout << "Foo\n";
}

Number CreateNumber()
{
    // Number n{10};

    // return n;

    return Number{ 10 };
}

int main()
{
    [[maybe_unused]] Number n1 = Number{ 3 };
    Foo( Number{ 3 } );

    [[maybe_unused]] auto n2 = CreateNumber();

    return 0;
}
