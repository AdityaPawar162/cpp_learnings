#include <iostream>
#ifdef __has_include
#if __has_include( <filesystem>)
#include <filesystem>
namespace fs = std::filesystem;
#elif __has_include( <experimental/filesystem>)
#include <experimental/filesystem>
namespace fs = std::experimental::filesystem;
#endif
#endif

int main()
{
    fs::path p = fs::current_path();
    std::cout << p << std::endl;
    return 0;
}