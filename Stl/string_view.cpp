#include <iostream>
#include <string>
#include <string_view>

/*Note if the string view is to a local object then once the function returns, string_view will be dangling.*/

int main()
{
    using namespace std::literals;
    std::string_view sv{ "Hello, World!" };
    std::string str( "Hello" );
    std::string_view sv2{ str };

    /*[[maybe_unused]] auto sv3 = "Using\0literals."sv;
    std::cout << "Size" << sv.length() << "\n";
    std::cout << sv3 << "\n";

    std::cout << "data() " << sv3.data() << "\n";
    std::cout << "front() " << sv3.front() << "\n";
    std::cout << "back() " << sv3.back() << "\n";

    auto f = sv3.find( "literals" );
    if( f != std::string_view::npos )
    {
        std::cout << "Found at " << f << "\n";
    }
    else
    {
        std::cout << "Not Found\n";
    }*/

    return 0;
}