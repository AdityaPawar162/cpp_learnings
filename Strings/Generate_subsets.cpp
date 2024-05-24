#include <bits/stdc++.h>
using namespace std;

// Function to generate all subsets of a string
void generateSubsets( string in, string out, int index )
{
    // Base condition: when all characters are processed
    if( index == in.length() )
    {
        cout << out << " ";
        return;
    }
    // Include the current character in the subset if it's not a duplicate
    char c = in[index];
    if( index == 0 || c != in[index - 1] )
    {
        generateSubsets( in, out + c, index + 1 );
    }
    // Exclude the current character and move to the next character
    generateSubsets( in, out, index + 1 );
}

int main()
{
    string s = "112";

    // Sort the string to handle duplicate characters
    sort( s.begin(), s.end() );
    // Generate subsets and print them
    generateSubsets( s, "", 0 );

    return 0;
}
