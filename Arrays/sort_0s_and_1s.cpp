#include <bits/stdc++.h>
using namespace std;

void sort_0_1(vector<int>&arr)
{
	int i = 0,j = arr.size()-1;
	while(i < j)
	{
		int currentLeftElement = arr[i];
		int currentRightElement = arr[j];
		if(currentLeftElement == 0)i++;
		if(currentRightElement == 1)j--;
		if(currentLeftElement == 1 && currentRightElement == 1){
		swap(arr[i],arr[j]);
		i++;
		j--;}
	}
	
	for( int i = 0; i < arr.size();i++)
	{
		cout << arr[i]<<" ";
	}
    
 }

int main()
{

   vector<int>arr  ;
   for(int i = 0; i < 6;i++)
   {
   	cin >> arr[i];
   }
   sort_0_1(arr);
	
    return 0;
}

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
