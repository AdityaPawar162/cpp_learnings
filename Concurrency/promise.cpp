/*
Provides a way to store value or an exception that will be available in the future.
*/
#include <future>
#include <iostream>
#include <thread>

// int main() {
//     std::promise<int> prom;
//     std::future<int> fut = prom.get_future();

//     std::thread t([&prom](){
//         prom.set_value(10);
//     });

//     std::cout << "Waiting for value from promise" << std::endl;
//     int value = fut.get();
//     std::cout << "Value from promise: " << value << std::endl;

//     t.join();
//     return 0;
// }
using namespace std::chrono_literals;
int Operation( std::promise<int> & data )
{
    auto f = data.get_future(); // get the future object from the promise object
    std::cout << "[Task] Waiting for the value from promise\n";
    auto count = f.get(); // get the value from the future object
    std::cout << "[Task] Value from promise acquired \n";

    int sum{};
    for( int i = 0; i < count; ++i )
    {
        sum += i;
        std::cout << '.';
        std::this_thread::sleep_for( 300ms );
    }

    return sum;
}

int main()
{
    std::promise<int> data;
    std::future<int> result = std::async(
        std::launch::async, Operation,
        std::ref( data ) ); // std::launch::async will create a new thread but std::launch::deferred will not create a
                            // new thread and will execute the function in the same thread
    std::this_thread::sleep_for( 1s );
    std::cout << "[main] settung the value in promise\n";
    data.set_value( 10 ); // You can set the value in the promise object only once
    if( result.valid() )
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
