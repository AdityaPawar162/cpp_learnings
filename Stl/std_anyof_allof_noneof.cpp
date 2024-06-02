#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> students_grades{ 90, 80, 85, 95, 70, 75, 72, 95, 85, 90 };
    if( std::all_of(
            std::begin( students_grades ), std::end( students_grades ), []( int grade ) { return grade >= 0; } ) )
    {
        std::cout << "All students have positive passed\n";
    }
    else
    {
        std::cout << "There are some students who have negative marks\n";
    }

    if( std::none_of(
            std::begin( students_grades ), std::end( students_grades ), []( int grade ) { return grade >= 80; } ) )
    {
        std::cout << "No student has scored below passing marks.\n";
    }
    else
    {
        std::cout << "There are students who scored below "
                     "passing marks.\n";
    }

    if( std::any_of(
            std::begin( students_grades ), std::end( students_grades ), []( int grade ) { return grade >= 95; } ) )
    {
        std::cout << "There are students who scored above or equal to 95\n";
    }
    else
    {
        std::cout << "There are some students who has 'exceptional' marks\n";
    }

    return 0;
}