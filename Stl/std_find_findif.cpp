#include <algorithm>
#include <iostream>
#include <vector>
#include <list>

struct Student
{
    std::string name;
    int grade{ 0 };
    Student( std::string n, int g ) : name{ n }, grade{ g } {}
};

bool operator==(const Student &student1,const Student &student2)
{
    return student1.name == student2.name && student1.grade == student2.grade;

}

int main()
{
    std::list<Student> students = {
        { "Lisa", 85 }, { "Corbin", 92 }, { "Aaron", 87 }, { "Daniel", 92 }, { "Mandy", 78 }, { "Regan", 92 },
    };
    auto found_student = std::find(std::begin(students),std::end(students),Student{"Aditya",92});
    if(found_student != std::end(students))
    {
        std::cout << "Aditya is present in students\n";
    }
    else
    {
        std::cout << "Aditya is not present in students\n";
    }

    auto found_student_if = std::find_if(std::begin(students),std::end(students),[](const Student &student){return student.grade > 90;});
    if(found_student_if != std::end(students))
    {
        std::cout << "There is or are students with grade greater than 90\n";
    }
    else
    {
        std::cout << "There is no student with grade greater than 90\n";
    }
    std::list<Student> student_find = {{"",92}};
    auto found_student_find = std::find_first_of(std::begin(students),std::end(students),std::begin(student_find),std::end(student_find),[](const Student &student1,const Student &student2){return student1.grade == student2.grade;});
    if(found_student_find != std::end(students))
    {
        std::cout << "First Student with grade 92 is present in students: " << found_student_find->name << '\n';
    }
    else
    {
        std::cout << "Student with grade 92 is not present in students\n";
    }

    auto found_student_end = std::find_end(std::begin(students),std::end(students),std::begin(student_find),std::end(student_find),[](const Student &student1,const Student &student2){return student1.grade == student2.grade;});
    if(found_student_end != std::end(students))
    {
        std::cout << "Last Student with grade 92 is present in students: " << found_student_end->name << '\n';
    }
    else
    {
        std::cout << "Student with grade 92 is not present in students\n";
    }

    

    return 0;

}