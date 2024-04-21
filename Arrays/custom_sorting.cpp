#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iterator>



struct Person{
    std::string name;
    int age;
    Person(std::string n,int a): name(n),age(a){}
    friend std::ostream &operator<< (std::ostream &os,const Person &p)
    {
        os << p.name << " (" << p.age << ") ";
        return os;
    }
};


int main()
{
    std::vector<Person> people{Person("Ravi",30),Person("Lisa",40),Person("Corbin",34)};
    auto compareName = [](const Person &a,const Person &b){return a.name < b.name;};

    std::sort(std::begin(people),std::end(people),compareName);
    std::ostream_iterator<Person> output(std::cout," ");
    std::copy(people.begin(), people.end(), output);
    std::cout << '\n';
    auto compareAge = [](const Person &a,const Person &b){return a.age < b.age;};
    std::sort(std::begin(people),std::end(people),compareAge);
    std::cout << " Compare by Age \n ";
    std::copy(people.begin(), people.end(), output);
    std::cout << '\n';

    return 0;
}