#include <future>
#include <iostream>
#include <thread>


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
    std::cout << "main() threading execution \n";
    if(result.valid())
    {
        [[maybe_unused]] auto status = result.wait_for(1s); // wait_for() returns a future_status enum value which can be used to check the status of the future object
        auto timepoint = std::chrono::steady_clock::now();
        timepoint += 1s;
        auto status1 = result.wait_until(timepoint); // accepts a timepoint and returns a future_status enum value
        switch (status1)
        {
        case std::future_status::ready:     // use async launch policy as std::launch::async to get ready status with extended timepoint
            std::cout << "Task is ready\n";
            break;
        case std::future_status::deferred:  // use async launch policy as std::launch::deferred to get deferred status  
            std::cout << "Task is synchronous\n";
            break;
        case std::future_status::timeout:
            std::cout << "Task is not ready\n"; // use async launch policy as std::launch::async to get timeout status with less timepoint
            break;    
        }
        auto sum = result.get();
        std::cout << sum << '\n';
    }
    else
    {
        std::cout << "Future is invalid\n";
    }
    
    
    return 0;
}