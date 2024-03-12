#include<iostream>
using namespace std;
int* rotate_arr(int arr[],int start,int end)
{ 
    int temp ;
	while(start<end)
	{
	temp = arr[start];
	arr[start] = arr[end];
	arr[end] = temp;
	start++;
	end--;	
	}
	return arr;
}
void left_rotate(int arr[],int n,int k)
{
	int m = k%n;
	int D[n];
	for(int i =0;i < n;i++)
	{
		D[i] = arr[i];
	}
	rotate_arr(D,0,m-1);
	rotate_arr(D,m,n-1);
	rotate_arr(D,0,n-1);
	
		for(int i =0;i < n;i++)
	{
		cout << D[i];
	}
}
int main()
{
   int arr[] = {1,3,5,7,9};
   int n = sizeof(arr)/sizeof(arr[0]);
   left_rotate(arr,n,2);
	return 0;
}

