#include <iostream>
#include <type_traits>

template <typename T>
void PrintType()
{
    if constexpr(std::is_integral_v<T>)
    {
        std::cout << "Integral type\n";
    }
    else if constexpr(std::is_floating_point_v<T>)
    {
        std::cout << "Floating point type\n";
    }
    else if constexpr(std::is_pointer_v<T>)
    {
        std::cout << "Pointer type\n";
    }
    else
    {
        std::cout << "Unknown type\n";
    }
}

template <typename T>
void Print(const T &value){
    if constexpr (std::is_pointer_v<T>)
    {
        std::cout << *value << "\n";
    }
    else if constexpr (std::is_array_v<T>)
    {
        for(const auto &element : value)
        {
            std::cout << element << " ";
        }
        std::cout << "\n";
    }
    std::cout << value << "\n";
}

int main()
{
    // PrintType<int>();
    // PrintType<float>();
    // PrintType<double>();
    // PrintType<int*>();
    // PrintType<float*>();
    // PrintType<double*>();
    // PrintType<std::string>();

    int value = 5;
    int *ptr = &value;
    Print(ptr);

    return 0;
}