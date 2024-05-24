#include <cstring>
#include <iostream>
#include <optional>

const char * GetErrorString( int errno )
{
    switch( errno )
    {
        case 0: return "Invalid Input";
        case 1: return "Connection not established yet\n";
        default: return "Unknown error";
    }
}

std::optional<const char *> GetErrorStringOp( int errno )
{
    switch( errno )
    {
        case 0: return "Invalid Input";
        case 1: return "Connection not established yet\n";
        default: return std::nullopt;
    }
}

class ContactName
{
    std::string first;
    std::optional<std::string> middle;
    std::string last;

public:
    ContactName( const std::string & f, const std::optional<std::string> & m, const std::string & l )
            : first( f ), middle( m ), last( l )
    {
    }
    void Print()
    {
        std::cout << first << " ";
        std::cout << middle.value_or( "" ) << " ";
        std::cout << last << '\n';
    }
};

int main()
{

    ContactName contact1{ "Ravi", std::nullopt, "Kumar" };
    contact1.Print();
    return 0;
    /*
    std::optional<int> value{5};
    // auto value = std::make_optional(5);
    if(value.has_value())
    {
        std::cout << "Value is " << value.value() << '\n';
    }
    if(value)
    {
        std::cout << *value << '\n';
    }

    // auto message = GetErrorString(0);
    // if(strlen(message) != 0)
    // {
    //     std::cout << message << '\n';
    // }
    // else{
    //     std::cout << "Unknown error number\n ";
    // }

    try{
    auto errorMessage = GetErrorStringOp(0);
    if(errorMessage.has_value())
    {
        std::cout << errorMessage.value() << '\n';
    }
    else{
        std::cout << "Unknown error number\n ";
    }

    errorMessage = GetErrorStringOp(0);
    if(errorMessage){
        std::cout << *errorMessage << '\n';
    }
    else{
        std::cout << "Unknown error number\n ";
    }}catch(const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }*/
}