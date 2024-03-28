/*
set - implemented as a binary tree,values are stored in sorted order.
*/

#include <iostream>
#include <set>

void Set()
{
    std::set<int,std::greater<int>> s{8,2,0,9,5};

    s.insert(1);
    s.insert(2);

    auto itr = s.begin();
   itr =  s.find(4);
    if(itr != s.end())
    {
        std::cout << "Element found" << std::endl;
    }
   else{
    std::cout << "Not\n"; 
   }
}

int main()
{
    Set();

    return 0;
}