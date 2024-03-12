#include<bits/stdc++.h>
using namespace std;
int main()
{
    int low,high,count = 0;
    cin >> low;
    cin >> high;
	for(int i = low; i <= high;i++)
	{
		if(i& 1 == 1)count++;
	}
	cout << count;
	return 0;
}

