#include <bits/stdc++.h>
using namespace std;
// Program to check whether the sentence is panagram
/*bool panagarm(string str)
{
    int arr[26] = {0};
    for(int i = 0 ; i < str.length();i++)
    {
        arr[str[i]-'a']++;
    }
    for(int j = 0; j < 26;j++)
    {
        if(arr[j] == 0){
        return 0;}

    }
        return 1;
}
int main()
{
    string str = "my name is aditya";
    cout << panagarm(str);
    return 0;
}*/
// Program to check whether the sentence is panagram , but both the cases are included

/*bool panagram(string s)
{
    int arr[26]= {0};
    for(int i = 0;i < s.length();i++)
    {
        if('A' <= s[i] && 'Z'>= s[i])
        arr[s[i]-'A']++;
        else if('a'<= s[i] && 'z' >= s[i])
        arr[s[i]-'a']++;
    }
    for(int i = 0;i < 26;i++)
    {
        if(arr[i]== 0)return 0;
    }
    return 1;
}
int main()
{
    string str = "The quick brown fox jumps over the lazy dog";
    cout << panagram(str);

    return 0;

}
*/

// Program to check whether the two words are anagram
bool anagram( string s1, string s2 )
{
    int n1 = s1.length();
    int n2 = s2.length();
    // sorting the strings
    sort( s1.begin(), s1.end() );
    sort( s2.begin(), s2.end() );

    for( int i = 0; i < n1; i++ )
    {
        if( s1[i] != s2[i] )
            return 0;
    }
    return 1;
}

int main()
{
    string s1 = "listen";
    string s2 = "sitlen";
    cout << anagram( s1, s2 );
    return 0;
}
