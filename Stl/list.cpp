// List is implemented as a double linked list, whereas forward list only as a linked list
#include <iostream>
#include <list>
#include <forward_list>

void List()
{
    std::list<int> coll;
    for (int i = 0; i < 5; i++)
    {
        coll.push_back(i * 10);
    }

    auto itr = coll.begin();
    while(itr != coll.end())
    {
        std::cout << *itr++ << '\n';
    }

    
}

void Forward_list()
{
    std::forward_list<int> coll;
    for (int i = 0; i < 5; i++)
    {
        coll.push_front(i*10);

    }
    for(auto x : coll)
    {
        std::cout << x << '\n';
    }
    coll.insert_after(coll.begin(),10);

    
    
}

int main()
{
    Forward_list();
    return 0;
}