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
        g_Mutex.lock();
        g_Data.push_back( i );
        /* This would be a deadlock condition because mutex will never unlock
         if(i == 500)
         return ;  */
        g_Mutex.unlock();
    }
}

void Download2()
{
    for( int i = 0; i < SIZE; ++i )
    {
        g_Mutex.lock();
        g_Data.push_back( i );
        g_Mutex.unlock();
    }
}

int main()
{
    std::thread thDownloader( Download );
    std::thread thDownloader2( Download2 );
    std::cout << "[Main]User started another operation\n";
    thDownloader.join();
    thDownloader2.join();
    std::cout << g_Data.size() << '\n';

    return 0;
}
