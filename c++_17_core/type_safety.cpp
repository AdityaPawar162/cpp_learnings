/*The class any describes a type-safe container for single values of any copy constructible type.

1) An object of class any stores an instance of any type that satisfies the constructor requirements or is empty, and
this is referred to as the state of the class any object. The stored instance is called the contained object. Two states
are equivalent if they are either both empty or if both are not empty and if the contained objects are equivalent. 2)
The non-member any_cast functions provide type-safe access to the contained object.*/
#include <any>
#include <iostream>

int main()
{

    std::any a = 5; // a has int type and value 5
                    // a.reset(); // a has no value
    // std::cout << std::any_cast<int>(a) << '\n';
    if( a.has_value() )
    {
        if( a.type() == typeid( int ) )
        {
            std::cout << std::any_cast<int>( a ) << '\n';
        }
    }
    try
    {
        std::cout << std::any_cast<int>( a ) << '\n';
    }
    catch( const std::bad_any_cast & e )
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}