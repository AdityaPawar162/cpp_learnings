#include <algorithm>
#include <iostream>
#include <vector>
void Vector()
{
    std::vector<int> coll{ 1, 2, 3, 4 };
    auto itr = coll.begin();
    while( itr != coll.end() )
    {
        std::cout << *itr++ << '\n';
    }
}

class Employee
{

public:
    std::string m_Name;
    int m_Id{ 0 };
    Employee( int id, std::string name ) : m_Name( name ), m_Id( id ) {}
    const int & getId() const
    {
        return m_Id;
    }
    const std::string & getName() const
    {
        return m_Name;
    }
    void setName( const std::string & newName )
    {
        m_Name = newName;
    }
};

int main()
{
    std::vector<Employee> employees;
    employees.reserve( 5 );
    employees.emplace_back( 1, "Lisa" );
    employees.emplace_back( 2, "Corbin" );
    employees.emplace_back( 3, "Aaron" );
    employees.emplace_back( 4, "Amanda" );
    employees.emplace_back( 5, "Regan" );
    for( const auto & [name, id] : employees )
    {
        std::cout << "Id: " << id << ", Name: " << name << '\n';
    }
    auto it = std::find_if(
        std::begin( employees ), std::end( employees ), []( const Employee & e ) { return e.getId() == 3; } );
    if( it != std::end( employees ) )
    {
        it->setName( "Chick" );
    }
    std::cout << "After modification: \n";
    for( const auto & [name, id] : employees )
    {
        std::cout << "Id: " << id << ", Name: " << name << '\n';
    }
    employees.erase(
        std::remove_if(
            std::begin( employees ), std::end( employees ), []( const Employee & e ) { return e.getId() == 2; } ),
        std::end( employees ) );
    std::cout << "After removal: \n";
    for( const auto & [name, id] : employees )
    {
        std::cout << "Id: " << id << ", Name: " << name << '\n';
    }

    return 0;
}