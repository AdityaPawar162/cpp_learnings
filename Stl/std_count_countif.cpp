#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> grades = { 85, 90, 78, 92, 88, 76, 95, 89 };
    if(std::count(std::begin(grades),std::end(grades),90))
    {
        std::cout << "90 is present in grades\n";
    }
    else
    {
        std::cout << "90 is not present in grades\n";
    }

    if(std::count_if(std::begin(grades),std::end(grades),[](int grade){return grade > 92;}))
    {
        std::cout << "There are grades greater than 92\n";
    }
    else
    {
        std::cout << "There are no grades greater than 92\n";
    }

    return 0;
}