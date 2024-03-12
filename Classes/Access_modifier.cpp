#include<iostream>
#include<string>
using namespace std;
class AbstractEmployee
{
	virtual void AskForPromotion() =0;
	   
};
class Employee:AbstractEmployee
{ 
private:
	string Name;
	  string Company;
	  int Age;
  public:
  	  void setName(string name)
  	  {
  	  	Name = name;
		}
		string getName()
		{
			return Name; 
		}
	  void Introduce()
	  {
	  	cout << "name" << Name;
	  	cout << " Company" << Company;
	  	cout << "Age";
	  }
	  Employee(string name,string company,int age )
	  {
	  	Name = name;
	  	Company  = company;
	  	Age = age;      
	  }
	  void AskForPromotion()
	  
	  {
	  	if(Age >= 30){
	  		cout << Name<<"got promoted"<<endl;
	  		   
		  }
		else
		 cout << Name << "not got promoted"<<endl;
	  } 
  	
};
class Developer:public Employee
{
  public:
  	string FavProgramming;
  	Developer(string name,string company,int age,string favProgramming)
	  :Employee(name,company,age)
	  
	  {
	  	FavProgramming = favProgramming;
	  }
	  void FixBug(){
	  	cout << getName()<<"fixed bug using"<<FavProgramming<<endl;
	  }
    	
};
int main()
{
    
    Developer d = Developer("Aditya","company",26,"python");
    d.FixBug();
    d.FixBug();
    d.FixBug();
    d.AskForPromotion();
    
}

