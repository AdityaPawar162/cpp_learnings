#include <pthread.h>
#include <iostream>
#include <list>
#include <mutex>
#include <string>
#include <thread>

std::list<int> g_Data;
const int SIZE = 10000;
std::mutex g_Mutex;

void Download()
{
    for( int i = 0; i < SIZE; ++i )
    {
        std::lock_guard<std::mutex> mtx( g_Mutex );
        g_Data.push_back( i );
        // This would be a deadlock condition because mutex will never unlock to avoid this we use std::lock_guard
        if( i == 500 )
            return;
    }
}

void Download2()
{
    for( int i = 0; i < SIZE; ++i )
    {
        std::lock_guard<std::mutex> mtx( g_Mutex );
        g_Data.push_back( i );
    }
}

int main()
{
    std::thread thDownloader( Download );
    std::thread thDownloader2( Download2 );
    std::cout << std::thread::hardware_concurrency() << '\n'; // Shows number of threads of a system
    auto id = thDownloader.get_id();                          // gets the id of the thread
    std::cout << id << '\n';
    std::cout << std::this_thread::get_id() << '\n'; // gets the id of main() function
    thDownloader.join();
    thDownloader2.join();
    std::cout << g_Data.size() << '\n';

    return 0;
}
