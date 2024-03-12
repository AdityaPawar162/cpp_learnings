#include<iostream>
using namespace std;
void swap(int *x,int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void sort(int arr[],int n)
{
	for(int i = 0;i < n-1;i++)
	{
		int min_index  = i;
		for(int j = i + 1;j < n;j++)
		{
			if(arr[j] < arr[min_index])
			{
				min_index = j;
			}
		
		}
			swap(&arr[min_index],&arr[i]);
	}
}

void print(int arr[],int n)
{
	for(int i = 0;i < n;i++)
	
	{
		cout << arr[i];
	}
	cout <<"\n";
}
int main()
{
    int arr[5] = {1,2,4,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);
	sort(arr,n);
	print(arr,n);
	return 0;
}

