#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

class Employee
{
    std::string m_Name;
    int m_Id;
    std::string ProLang;

public:
    Employee( const std::string & n, int id, const std::string & progLang )
            : m_Name( n ), m_Id( id ), ProLang( progLang )
    {
    }

    const std::string getName() const
    {
        return m_Name;
    }

    int getId() const
    {
        return m_Id;
    }
    const std::string getProLang() const
    {
        return ProLang;
    }

    bool operator<( const Employee & e ) const
    {
        return m_Id < e.m_Id;
    }
};

void UserDefined()
{
    std::vector<Employee> v{
        Employee{ "Umar", 101, "C++" },
        Employee{ "Bob", 202, "Python" },
        Employee{ "Joey", 303, "Julia" },
    };

    std::sort( v.begin(), v.end(), []( const auto & e1, const auto & e2 ) { return e1.getName() < e2.getName(); } );
}

struct EmpCompare
{
    bool operator()( const Employee & e1, const Employee & e2 ) const
    {
        return e1.getId() < e2.getId();
    }
};

void Set()
{
    std::set<Employee, EmpCompare> v{ Employee{ "Umar", 101, "C++" }, Employee{ "Bob", 202, "Python" },
                                      Employee{ "Joey", 303, "Julia" } };
}

int main()
{
    Set();

    return 0;
}