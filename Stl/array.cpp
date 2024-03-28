#include <iostream>
#include <array>

void Array(){
    std::array<int,5> arr{5,1,9,8};
    for (auto it : arr)
    {
        std::cout << it << " ";
    }
    std::cout << '\n';
   

   std::cout << "arr.data " << static_cast<void*>(arr.data())<< '\n'; // Give the pointer to the underlying data to the data array
    
}

int main(){
    Array();

    return 0;
}