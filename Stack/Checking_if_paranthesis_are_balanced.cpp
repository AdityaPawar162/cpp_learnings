#include <cstring>
#include <iostream>
#include <stack>
using namespace std;
bool ArePair( char opening, char closing )
{
    if( opening == '(' && closing == ')' )
        return true;
    else if( opening == '{' && closing == '}' )
        return true;
    else if( opening == '[' && closing == ']' )
        return true;
    return false;
}

bool CheckParanthesis( string exp )
{
    stack<char> S;
    for( int i = 0; i < exp.length(); i++ )
    {
        if( exp[i] == '(' || exp[i] == '{' || exp[i] == '[' )
        {
            S.push( exp[i] );
        }
        else if( exp[i] == ')' || exp[i] == '}' || exp[i] == ']' )
        {
            if( S.empty() || !ArePair( S.top(), exp[i] ) )
                return false;
            else
                S.pop();
        }
    }
    return S.empty() ? true : false;
}
int main()
{
    string expression;
    cout << "Enter the expression";
    cin >> expression;
    if( CheckParanthesis( expression ) )
    {
        cout << "Balanced\n";
    }
    else
    {
        cout << "not balanced\n";
    }
}
