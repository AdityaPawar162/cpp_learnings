#include <algorithm>
#include <iostream>
#include <string>

void reverseCharacters( std::string & msg, int leftIndex, int rightIndex )
{
    while( leftIndex < rightIndex )
    {
        std::swap( msg[leftIndex], msg[rightIndex] );
        leftIndex++;
        rightIndex--;
    }
}

void reversewords( std::string & str )
{

    reverseCharacters( str, 0, str.length() - 1 );
    for( int i = 0, j = 0; j <= str.length(); j++ )
    {
        if( j == str.length() || str[j] == ' ' )
        {
            reverseCharacters( str, i, j - 1 );
            i = j + 1;
        }
    }
}

int main()
{
    std::string msg = "find you will pain only go you recordings security the into if";
    reversewords( msg );
    std::cout << msg;

    return 0;
}