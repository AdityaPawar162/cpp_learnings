#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <vector>

// Stable sorts the elements in the range [first, last) in ascending order preserving the order of equal elements same.

struct Employee
{
    int age;
    std::string name; // Does not participate in comparisons
};

bool operator<( const Employee & lhs, const Employee & rhs )
{
    return lhs.age < rhs.age;
}

int main()
{
    std::vector<Employee> v{ { 108, "Zaphod" }, { 32, "Aditya" }, { 32, "Arthur" }, { 108, "Ford" } };

    std::stable_sort( v.begin(), v.end() );

    for( const Employee & e : v )
        std::cout << e.age << ", " << e.name << '\n';
}