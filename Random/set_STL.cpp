#include<bits/stdc++.h>
using namespace std;
int main()
{
    set<int> lst;
    for(int i = 0;i <=5;i++)
    {
    	lst.insert(i);
	}
	cout << ".........Inserting in SET.........."<<endl;
	set<int>::const_iterator it;
	for(it = lst.begin();it != lst.end();++it)
	{
		cout << *it<<' ';
	}
	cout <<endl;
	return 0;
}

