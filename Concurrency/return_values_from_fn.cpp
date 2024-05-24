#include <future>
#include <iostream>
#include <thread>
#include <vector>

int Add( int x, int y )
{
    return x + y;
}

int Square( int x )
{
    return x * x;
}

int Compute( const std::vector<int> & data )
{
    using namespace std;
    int sum{};
    for( auto e : data )
    {
        sum += e;
        std::this_thread::sleep_for( 1s );
        std::cout << '.';
    }

    return sum;
}

int main()
{
    std::packaged_task<int( int, int )> taskAdd{ Add };
    taskAdd( 3, 5 );
    std::future<int> ft = taskAdd.get_future();
    auto result         = ft.get();
    std::cout << result << '\n';

    std::packaged_task<int( const std::vector<int> & )> taskCompute{ Compute };
    auto ftcompute = taskCompute.get_future();
    std::vector<int> data{ 4, 5, 6, 7 };
    std::thread threadCompute( std::move( taskCompute ), data );
    // taskCompute(data);
    std::cout << ftcompute.get() << '\n';

    std::cout << "End of main\n";
    threadCompute.join();

    return 0;
}