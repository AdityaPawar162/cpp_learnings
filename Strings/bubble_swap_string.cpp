#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cout << "string: ";
	cin>>s;
	for(int i = 0; i < s.length()-1;i++)
	{
		for(int j = i +1; j < s.length();j++)
		{
			if(s[i] > s[j])swap(s[i],s[j]);
			
		}
	}
	for(int i = 0; i  < s.length();i++)cout << s[i];
	return 0;
}
