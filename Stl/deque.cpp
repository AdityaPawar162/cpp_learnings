#include <iostream>
#include <deque>

void Deque()
{
    std::deque<int> coll;
    for(int i = 0;i < 5;i++)
    {
        coll.push_back(i*10);
    }

    for(int i = 0;i < 5;i++)
    {
        coll.push_front(i*10);
    }
    coll[0] = 100;
    auto itr = coll.begin();
    while(itr != coll.end())
    {
        std::cout << *itr++ << '\n';
    }

    coll.insert(coll.begin(),70);
    coll.erase(coll.end() - 4 );
    coll.pop_back();
    coll.pop_front();
}

int main()
{
    Deque();

    return 0;
}