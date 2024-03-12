#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class Employee
{
	char Name[20];
	int ID;
	double salary;
	public:
		void accept()
		{
			cout << "\n Enter name:";
			cin >> Name;
			cout << "\n Enter Id";
			cin >> ID;
			cout << "\n Enter salary";
			cin >> salary;
			
		}
		void display(){
			cout << "\n Name "<<Name;
			cout << "\n Id" <<ID;
			cout << "\n salary"<<salary;
		}
};
int main()
{ 
	Employee o[5];
	fstream f;
	int i,n;
	
	f.open("b16.txt",ios::in);
	cout << "\n How many employee information do you need to store?";
	cin >> n;
	cout << "\n Enter information of employee in this format(NAME/ID/SALARY)";
	for(i = 0;i < n;i++)
	{
		cout << "\nENter informaiton of "<< i << "\n Employee";
		o[i].accept();
		f.write((char*)&o[i],sizeof(o[i]));
		
	}
	f.close();
	return 0;
}

