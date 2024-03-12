#include<iostream>
using namespace std;
class Complex;
class Calculator{
	public:
		int add(int a,int b){
			return (a+b);
		}
		int sumRealComplex(Complex,Complex);
		int sumCompComplex(Complex,Complex);
};
class Complex
{
	private:
		int a,int b;
		friend class Calculator;
	public:
		void SetNumber(int n1,int n2){
			a = n1;
			b = n2;
		}
		 void printNumber()
		 {
		 	cout << "Your number is"<< a <<"+"<<b<<"i"<< endl;
		 	
		 } 
		
	
		
		
};
int calculator ::sumRealComplex(Complex o1,Complex o2){
	return (o1.
}
int main(){
	return 0;
}
