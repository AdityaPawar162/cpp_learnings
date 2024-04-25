#include <iostream>
#include <string_view>
/*String view is only a non owning view of a sequence of characters.*/
void PrettyPrint(const std::string &message,char ch) // Separate memory is allocated for message and copied to it.
{
    for(size_t x = 0; x < message.length(); ++x)
    {
        std::cout << ch;
    }
    std::cout << "\n";
    std::cout << message << "\n";
}

void PrettyPrint(std::string_view message,char ch) // No separate memory is allocated for message and copied to it.
{
    for(size_t x = 0; x < message.length(); ++x)
    {
        std::cout << ch;
    }
    std::cout << "\n";
    std::cout << message << "\n";
}

int main()
{
    std::string message{"Hello, World!"};
    PrettyPrint(message,'*');
    std::string_view sv{message};
    PrettyPrint(sv,'-');
    std::string_view sv2{message.c_str(),5};
    PrettyPrint(sv2,'+');
    return 0;
}