#include <cstring>
#include <iostream>
#include <stack>
using namespace std;
bool isOperator( char c )
{
    if( c == '*' || c == '+' || c == '/' || c == '-' )
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isOperand( char c )
{
    if( c > '0' && c <= '9' )
    {
        return true;
    }
    else
    {
        return false;
    }
}
int IsRightAssociative( char op )
{
    if( op == '^' )
        return true;
    return false;
}
int GetOPeratorWeight( char op )
{
    int weight = -1;
    switch( op )
    {
        case '+':
        case '-': weight = 1; break;
        case '*':
        case '/': weight = 2; break;
        case '^': weight = 3; break;
    }
    return weight;
}
bool IsOpeningParantheses( char c )
{
    if( c == '(' || c == '{' || c == '[' )
        return true;
    return false;
}
bool IsClosingParantheses( char c )
{
    if( c == ')' || c == '}' || c == ']' )
        return true;
    return false;
}
int HasHigherPrecedence( char op1, char op2 )
{
    int Getweight1 = GetOPeratorWeight( op1 );
    int Getweight2 = GetOPeratorWeight( op2 );
    if( Getweight1 == Getweight2 )
    {
        if( IsRightAssociative( op1 ) )
            return false;
        else
            return true;
    }
    return Getweight1 > Getweight2 ? true : false;
}
string InfixToPostfix( string expression )
{
    stack<char> S;
    string postfix;
    for( int i = 0; i < expression.length(); i++ )
    {
        if( expression[i] == ' ' || expression[i] == ',' )
            continue;

        else if( isOperand( expression[i] ) )
        {
            postfix += expression[i];
        }
        else if( isOperator( expression[i] ) )
        {

            while( !S.empty() && IsOpeningParantheses( S.top() ) && HasHigherPrecedence( S.top(), expression[i] ) )
            {
                postfix += S.top();
                S.pop();
            }
            S.push( expression[i] );
        }
    }
    while( !S.empty() )
    {
        postfix += S.top();
        S.pop();
    }

    return postfix;
}
int main()
{
    string expression;
    cout << "Enter Infix Expression \n";
    getline( cin, expression );
    string postfix = InfixToPostfix( expression );
    cout << "Output = " << postfix << "\n";
}
