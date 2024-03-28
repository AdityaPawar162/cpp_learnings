#include <bits/stdc++.h>
using namespace std;

set<int> setInsert(int arr[],int n); //Function to insert elements of array into a set and return a set


void setDisplay(set<int>s); //function to print the elements of the set


void setErase(set<int>&s,int x); //function to erase x from set if it exists

set<int> setInsert(int arr[],int n)
{
    set<int>s;
    
    
    //Your code here to insert arr into s
    for(int i = 0; i < n;i++){
    s.insert(arr[i]);
    }
    
    return s;
    
}


void setDisplay(set<int>s)
{
    //Your code here to display elements of s
    for(const auto x : s)
    {
        cout << x << " ";
    }
    cout<<endl;
}


void setErase(set<int>&s,int x)
{
    auto itr = s.find(x);
   //write if condition here
   if(itr != s.end()){
    cout << "erased "<<x;
   }
   else{
    
    //write else condition here
    cout<<"not found";
   }
    
    
    cout<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n]; //array of size n
        for(int i=0;i<n;i++)
            cin>>arr[i]; //Input the array
        
        set<int>s=setInsert(arr,n); //call the insert function that returns a set
        setDisplay(s);// display the inserted set
        // int x;
        // cin>>x; //x element that needs to be erased from set
        
        // setErase(s,x); //try to erase x from set
        // setDisplay(s); //print the set after erase operation
        
        
    }
	return 0;
}
