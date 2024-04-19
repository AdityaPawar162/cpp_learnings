#include <future>
#include <iostream>
#include <thread>

/* Two ways to call async function
   future<return_type> async(function_name, args) 
   future<return_type> async(launch_policy,function_name, args)*/
using namespace std::chrono_literals;
int Operation(int count)
{
    int sum{};
    for (int i = 0; i < count; ++i)
    {   
        sum += i;
        std::cout << '.';
        std::this_thread::sleep_for(300ms);
    }

    return sum;
    
}

int main()
{

    std::future<int>  result = std::async(std::launch::async,Operation,10); // std::launch::async will create a new thread but std::launch::deferred will not create a new thread and will execute the function in the same thread
    std::this_thread::sleep_for(1s);
    std::cout << "main() threading execution";
    if(result.valid())
    {
       
        auto sum = result.get();
        std::cout << sum << '\n';
    }
    else
    {
        std::cout << "Future is invalid\n";
    }
    
    
    return 0;
}