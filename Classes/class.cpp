#include <bits/stdc++.h>
using namespace std;
class C;
class A
{
    int a = 10;

public:
    friend class C;
};
class B
{
    int b = 20;
    friend class C;
};
class C
{
public:
    A a1;
    B b1;
    C()
    {
        cout << a1.a << " " << b1.b;
    }
};
int main()
{
    C c1;
    return 0;
}
