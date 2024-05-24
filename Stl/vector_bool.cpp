#include <iostream>
#include <vector>

/*
When accessing an element from std::vector<bool>, you don’t get a normal reference as you do with other vector types.
Instead, you get a proxy object. This is why modifying ref in the example doesn’t change the actual value in the vector.
*/

void bool_vec()
{
    std::vector<bool> boolVec{ true, false, true, true, false };
    boolVec[1] = true;
    std::cout << "boolVec[1]: " << boolVec[1] << std::endl;
    auto ref = boolVec[1];
    ref      = false;
    std::cout << "boolVec[1] after modifying copy: " << boolVec[1] << std::endl;

    // Iterating over the vector
    for( bool val : boolVec )
    {
        std::cout << val << " ";
    }
    std::cout << '\n';
    //  Pushing elements
    boolVec.push_back( true );
    // Resizing the vector
    boolVec.resize( 10, true );
    // Capacity and size of the vector
    std::cout << "Capacity: " << boolVec.capacity() << " Size: " << boolVec.size() << std::endl;
    // Clearing the vector
    boolVec.clear();
}

int main()
{
    bool_vec();
    return 0;
}