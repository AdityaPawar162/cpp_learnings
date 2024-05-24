#include <iostream>
using namespace std;
class Base
{
public:
    void display()
    {
        cout << "\nIn Base" << endl;
    }
};
class Derived : public Base
{
public:
    void display()
    {
        cout << "\nIn Derived" << endl;
    }
};
int main()
{
    Base * ptr;
    Derived d;
    Base b;
    ptr = &b;
    ptr->display();
    ptr = &d;
    ptr->display();
    return 0;
}
