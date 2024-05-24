#include <iostream>
#include <vector>

std::vector<int> mergeVectors( const std::vector<int> & myVector, const std::vector<int> & alicesVector )
{
    // Combine the sorted vectors into one large sorted vector
    std::vector<int> result;
    int i = 0;
    int j = 0;
    while( i < myVector.size() && j < alicesVector.size() )
    {
        if( myVector[i] < alicesVector[j] )
        {
            result.push_back( myVector[i] );
            ++i;
        }
        else if( myVector[i] > alicesVector[j] )
        {
            result.push_back( alicesVector[j] );
            ++j;
        }
    }
    // Corner case
    if( i == myVector.size() )
    {
        for( int k = j; k < alicesVector.size(); ++k )
        {
            result.push_back( alicesVector[k] );
        }
    }
    else if( j == alicesVector.size() )
    {
        for( int k = i; k < myVector.size(); ++k )
        {
            result.push_back( myVector[k] );
        }
    }

    return result;
}

int main()
{
    const std::vector<int> myVector{ 2, 4, 6 };
    const std::vector<int> alicesVector{ 1, 3, 7 };
    const auto actual = mergeVectors( myVector, alicesVector );
    for( auto i : actual )
    {
        std::cout << i << " ";
    }
    return 0;
}