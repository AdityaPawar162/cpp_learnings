#include<iostream>
using namespace std;
//EXAMPLE OF SWAP
int reverse(int *arr,int start,int end)
{
    int mid = (start + end)/2;
    for (int i = 0; i < mid; i++)
    {
        swap(arr[i],arr[end -(mid - i +1)]);
    }
    return *arr;
}
int main(){
//To reverse an array
int arr[5] ={1,2,3,4,5};
//in = arr; 
int N = sizeof(arr)/sizeof(arr[0]);
cout << reverse(arr,1,N);

    return 0;
}
