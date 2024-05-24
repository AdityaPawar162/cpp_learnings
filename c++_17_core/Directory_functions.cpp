#include <filesystem>
#include <iostream>
#include <vector>
namespace fs = std::filesystem;
void DirectoryOperations( std::string_view file )
{
    fs::path currentPath{ file };
    if( !fs::exists( currentPath ) )
    {
        std::cerr << "Path does not exist\n";
        return;
    }
    currentPath /= "new_directory";
    try
    {
        std::cout << fs::current_path() << '\n';
        std::cout << "Changing path\n";
        std::error_code ec;
        fs::current_path( currentPath, ec );
        if( ec )
        {
            std::cerr << "Error: " << ec.message() << '\n';
            return;
        }
        std::cout << "Changed path to: " << fs::current_path() << '\n';
    }
    catch( const fs::filesystem_error & e )
    {
        std::cerr << "Exception: " << e.what() << '\n';
    }
}

int main()
{
    DirectoryOperations( "/home/adi/Documents/cpp/cpp_learnings" );
    return 0;
}