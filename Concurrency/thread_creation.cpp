#include <chrono>
#include <iostream>
#include <list>
#include <string>
#include <thread>

std::list<int> g_Data;
const int SIZE = 5000000;

template<typename TimeT = std::chrono::milliseconds>
struct measure
{
    template<typename F, typename... Args>
    static typename TimeT::rep execution( F && func, Args &&... args )
    {
        auto start = std::chrono::steady_clock::now();
        std::forward<decltype( func )>( func )( std::forward<Args>( args )... );
        auto duration = std::chrono::duration_cast<TimeT>( std::chrono::steady_clock::now() - start );
        return duration.count();
    }
};

class String
{

public:
    String()
    {
        std::cout << "String()\n";
    }

    String( const String & )
    {
        std::cout << "String(const String &)\n";
    }

    String & operator=( const String & )
    {
        std::cout << "operator=(const String&)\n";
        return *this;
    }

    ~String()
    {
        std::cout << "~String()\n";
    }
};

void Download( [[maybe_unused]] String & file )
{
    std::cout << "[Download] Started download\n";
    for( int i = 0; i < SIZE; ++i )
    {
        g_Data.push_back( i );
    }
    std::cout << "[Download] Finished download\n";
}

int main()
{

    String file;
    std::cout << "[Main]User started Download\n";
    std::thread thDownloader(
        Download,
        std::ref(
            file ) ); // We use std::ref to pass arguments by reference, otherwise it constructs copy constructor is called
    // thDownloader.detach();

    std::cout << "[Main]User started another operation\n";
    thDownloader.join();

    return 0;
}
