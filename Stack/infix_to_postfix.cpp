#include <iostream>
#include <stack>
#include <string>
using namespace std;

int Perform( int Op1, int Op2, char op )
{
    switch( op )
    {
        case '+': return Op1 + Op2;
        case '-': return Op1 - Op2;
        case '*': return Op1 * Op2;
        case '/': return Op1 / Op2;
        default: return 0; // Handle invalid operator
    }
}

int EvaluatePostfix( string exp )
{
    stack<int> S;
    for( int i = 0; i < exp.length(); i++ )
    {
        if( isdigit( exp[i] ) )
        {
            S.push( exp[i] - '0' ); // Convert char digit to int
        }
        else if( exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' )
        {
            int Op2 = S.top();
            S.pop();
            int Op1 = S.top();
            S.pop();
            int res = Perform( Op1, Op2, exp[i] );
            S.push( res );
        }
    }
    return S.top();
}

int main()
{
    string exp = "42+5*";
    cout << "Result: " << EvaluatePostfix( exp ) << endl;
    return 0;
}
