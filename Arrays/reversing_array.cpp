#include<iostream>
using namespace std;
void reverseArray(int arr[],int start,int end)
{
	while(start < end)
	{
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}
void Printarray(int arr[],int size)
{
	for(int i= 0;i < size;i++ )
	{
		cout << arr[i]<<" ";
		
	}
}
int main(){
   int arr[]= {1,2,3,4,5};
   int d = 2;
    int N = sizeof(arr)/sizeof(arr[0]);
//    d = d%N;
    reverseArray(arr,0,d-1);
	reverseArray(arr,d ,N-1);
	reverseArray(arr,0,N-1);
    Printarray(arr,N);
}
