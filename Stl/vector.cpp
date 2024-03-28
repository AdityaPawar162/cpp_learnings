#include <iostream>
#include <vector>

void Vector()
{
    std::vector<int> coll{1,2,3,4};
    auto itr = coll.begin();
    while(itr != coll.end())
    {
        std::cout << *itr++ << '\n';
    }


}

int main()
{
    Vector();

    return 0;
}