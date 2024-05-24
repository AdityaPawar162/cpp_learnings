#include <iostream>
using namespace std;
/*#define size 100
struct stack{
    int s[size];
    int top;
}st;
stack S1[size];
int top = -1;
int stfull()
{
  if(st.top >= size -1)
  return 1;
  else
  return 0;

}*/
int fact( int n )
{
    int my_new_func( int n, int f );
    return my_new_func( n, 1 );
}
int my_new_func( int n, int f )
{
    if( n == 1 )
    {
        return f;
    }
    my_new_func( n - 1, n * f );
    //	cout << "this is f"<<f;
}
int main()
{
    cout << fact( 4 ) << endl;
    return 0;
}
