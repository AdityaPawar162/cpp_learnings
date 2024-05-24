#include <iostream>
using namespace std;

// Destructor never takes an argument nor does does it return any value
class num
{
public:
    int count;
    num()
    {
        count++;
        cout << "This is the time when constructor is called for object number" << count << endl;
    }
    ~num()
    {
        cout << "This is the time when my destructor is called for ibject  number" << count << endl;
        count--;
    }
};
int main()
{
    cout << "We are inside our main finction" << endl;
    cout << "creating forst bject n1" << endl;
    num m1;
    {
        cout << "Entering this block" << endl;
        cout << "Creating two more objects" << endl;
        num n2, n3;
        cout << "Existing the block" << endl;
    }
    cout << "back to main" << endl;
    return 0;
}
