#include <iostream>
#include <vector>

int majorityElement( std::vector<int> & nums )
{
    int candidate = -1;
    int votes     = 0;

    // Finding the candidate
    for( auto x : nums )
    {
        if( votes == 0 )
        {
            candidate = x;
            votes     = 1;
        }
        else if( x == candidate )
        {
            votes++;
        }
        else
        {
            votes--;
        }
    }
    // Verifying if the candidate is the majority element
    int count = 0;
    for( auto x : nums )
    {
        if( x == candidate )
        {
            count++;
        }
    }
    // Returning the majority element if it exists, otherwise returning -1
    if( count > nums.size() / 2 )
    {
        return candidate;
    }
    else
    {
        return -1;
    }
}

int main()
{
    std::vector<int> nums = { 2, 2, 1, 1, 1, 2, 2 };
    int majority          = majorityElement( nums );

    if( majority != -1 )
    {
        std::cout << "Majority element is: " << majority << std::endl;
    }
    else
    {
        std::cout << "No majority element found." << std::endl;
    }

    return 0;
}
