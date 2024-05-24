// Kadane algorithm is used to calculate the maximum value of sum of a sub array
#include <bits/stdc++.h>
using namespace std;
int max_sum_subarray( vector<int> & nums )
{
    int max_ending_here = 0;
    int max_so_far      = INT_MIN;
    for( auto x : nums )
    {
        max_ending_here += x;
        if( max_so_far < max_ending_here )
            max_so_far = max_ending_here;
        if( max_ending_here < 0 )
            max_ending_here = 0;
    }

    return max_so_far;
}
/*
int max_sum_subarray(vector<int>& nums)
{
    int max_ending_here = 0;
    int max_so_far = INT_MIN;
    for(auto x : nums)
    {
      max_ending_here += x;
      max_so_far = max(max_so_far,max_ending_here);
      max_ending_here = max(max_ending_here,0);
    }
 return max_so_far;
}*/
int main()
{
    vector<int> arr = { -2, -3, 4, -1, -2, 1, 5, -3 };
    cout << max_sum_subarray( arr );
    return 0;
}
