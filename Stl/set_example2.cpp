#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    //Complete this function
    vector<int> uniqueSorted(int arr[], int n)
    {
        //Your code here
        vector<int> v;
        set<int> s;  // Use a set to store unique elements

        for (int i = 0; i < n; i++) {
            s.insert(arr[i]);  // Insert elements into the set
        }

        // Copy unique elements from the set to the vector
        for (int num : s) {
            v.push_back(num);
        }

        // Sort the vector
        sort(v.begin(), v.end());

        return v;
    }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        
        for(int i=0;i<n;i++)
        cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.uniqueSorted(arr,n);
        for(auto i:ans)
        cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}