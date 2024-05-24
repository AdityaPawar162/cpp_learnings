#include <iostream>
using namespace std;
class Employee
{
    int id;
    static int count;

public:
    void setData()
    {
        cout << "Enter the id :";
        cin >> id;
        count++;
    }
    void getData()
    {
        cout << "The id you have entered is :" << id << "and the count is " << count;
    }
};
int Employee ::count; // Default value will be set as zero

int main()
{
    Employee harry, john, lavish;
    harry.setData();
    harry.getData();

    john.setData();
    john.getData();

    lavish.setData();
    lavish.getData();
    return 0;
}
