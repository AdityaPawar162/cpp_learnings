#include <iostream>
#include <type_traits>

template <typename T>
void processNumericalData(T data)
{
    if constexpr (std::is_integral_v<T>)
    {
        std::cout << "Processing integer: " << data << '\n';
    }
    else if constexpr (std::is_floating_point_v<T>)
    {
        std::cout << "Processing float: " << data << '\n';
    }
    else
    {
        static_assert(std::is_arithmetic_v<T> == false, "Unsupported type.");
    }
}


int main()
{
    processNumericalData(10);
    processNumericalData(10.5f);
    processNumericalData(10.5);

}
