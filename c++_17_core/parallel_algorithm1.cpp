#include <algorithm>
#include <chrono>
#include <execution>
#include <iostream>
#include <random>
#include <string_view>
#include <vector>

class Timer
{
    std::chrono::steady_clock::time_point m_start;

public:
    Timer() : m_start{ std::chrono::steady_clock::now() } {}
    void ShowResult( std::string_view message )
    {
        auto end        = std::chrono::steady_clock::now();
        auto difference = std::chrono::duration_cast<std::chrono::milliseconds>( end - m_start );
        std::cout << message << " " << difference.count() << " ms\n";
    }
};

constexpr unsigned VEC_SIZE{ 1000000 };
std::vector<long> CreateVector()
{
    std::vector<long> vec;
    vec.reserve( VEC_SIZE );
    std::default_random_engine engine{ std::random_device{}() };
    std::uniform_int_distribution<long> dist{ 0, VEC_SIZE };
    for( unsigned i = 0; i < VEC_SIZE; ++i )
    {
        vec.push_back( dist( engine ) );
    }
    return vec;
}

int main()
{
    auto data = CreateVector();
    Timer t;
    //   std::sort(std::execution::par,data.begin(),data.end());
    //   std::sort(std::execution::par,data.begin(),data.end());

    auto result = std::reduce(
        data.begin(), data.end(), 0L ); // std::reduce is a parallel algorithm that reduces the range [first, last) into
                                        // a single value using the binary_op operation.

    t.ShowResult( "std::sort" );
}