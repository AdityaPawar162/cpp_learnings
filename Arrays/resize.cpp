#include <iostream>
#include <vector>

int main()
{
    std::vector<int> numbers{ 1, 2, 3, 4, 5 };
    auto printVectorDetails = [&]()
    {
        std::cout << "Vector Elements: ";
        for( auto & num : numbers )
        {
            std::cout << num << " ";
        }
        std::cout << "\nSize" << numbers.size() << "\n";
        std::cout << "\nCapacity" << numbers.capacity() << "\n";
    };

    std::cout << "Intial Vector\n";
    printVectorDetails();
    numbers.resize( 8 );
    std::cout << "After Resizing to 8 elements\n";
    printVectorDetails();
    numbers.resize( 3 );
    std::cout << "After Resizing to 3 elements\n";
    printVectorDetails();
    std::cout << "Reducing size doesn't change capacity\n";
    std::cout << "capacity after resize: " << numbers.capacity() << "\n";

    return 0;
}