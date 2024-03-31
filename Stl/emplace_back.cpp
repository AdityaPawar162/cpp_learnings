#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>


class Integer{
   int integer;
   public:
   Integer(const int i) noexcept : integer(i){}
    int GetInt() const {
    return integer;
   }

};

void Emplace()
{
    std::vector<Integer> vInt;
    Integer val{5};
     
    vInt.emplace_back(val); // Its a vardiac template, when you want to create objects with directly inside containers.
    std::vector<std::pair<int,std::string>> data;
    data.push_back(std::pair<int,std::string>{100,"C++"});
    data.emplace_back(100,"C++");
}


template <typename Container>
void Print(const Container &cont,const char*msg= "" )
{
    std::cout << "Printing container " << msg << " \n";
    for(auto a : cont)
    {
        std::cout << a << " ";
    }
    std::cout << '\n';
}

int main()
{
    std::set<int> data{1,4,6,3};
    data.emplace_hint(data.begin(),0);
/*    auto it = data.find(6);
    if(it != data.end())
    {
        std::cout << "Found" ;
    }
    else{
        std::cout << "Not found";
    }

    auto found = data.contains(6); // c++ 20 introduced "contains" member that returns boolean value, after checking whether there is a value present or not
    if(found)
    {
        std::cout << "found";
    }

*/
    
    std::set<std::string> names{"Hulk","Iron Man","Captain America"};
    auto it = names.find("Hulk");
    auto name = *it;
    name[0]  = 'it';
    names.erase(it);
    names.insert(name);  // This code is for replacing a value in set

    auto node = names.extract(it);
    node.value()[0] = 'U';
    names.insert(std::move(node));  // This code is for replacing a value in set without copying the variable



    return 0;
}