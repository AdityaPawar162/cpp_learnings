#include <iostream>
#include <map>

struct Person
{

    std::string m_Name;
    int m_Age;
    Person() = default;
    Person( const std::string & name, int age ) : m_Name( name ), m_Age( age ) {}
};

int main()
{
    Person person( "Cherno", 24 );
    /*
        Old way of accessing the members of the struct
    auto name = person.m_Name;
    auto age = person.m_Age;
    */
    // New way of accessing the members of the struct
    auto [name, age] = person;
    std::cout << person.m_Name << " " << person.m_Age << std::endl;

    // Another example of structure bindings
    std::pair<int, int> p1{ 3, 5 };
    auto [key, value] = person;
    std::cout << key << " " << value << std::endl;

    // Another example of structure bindings
    std::map<int, std::string> errorinfo{ { 1, "File not found" }, { 2, "Access denied" } };

    // Iterating through the map using iterators
    for( auto err : errorinfo )
    {
        std::cout << err.first << " " << err.second << std::endl;
    }

    // Iterating through the map using structure bindings
    for( const auto & [errorno, errormsg] : errorinfo )
    {
        std::cout << errorno << " " << errormsg << std::endl;
    }

    return 0;
}
