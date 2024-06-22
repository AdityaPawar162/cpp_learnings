#include <iostream>
#include <vector>
#include <numeric>

int main()
{
    std::vector<double> values = { 8.0, 16.0, 64.0, 256.0, 4096.0 };
    // Create a vector to store the results.
    std::vector<double> results(values.size());
    // Lambda to find the divide the values
    auto lambda = [](double x,double y){
        if( x == 0)
        {   
            return 0.0;
        }
        else{
            return y/x;
        }
    };
    std::adjacent_difference(std::begin(values),std::end(values),std::begin(results),lambda);
    for(const auto &x : results)
    {
        std::cout << x << " ";
    }
    std::cout << '\n';

    return 0;
}