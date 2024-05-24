#include <algorithm>
#include <filesystem>
#include <iostream>
#include <vector>
namespace fs = std::filesystem;

void TraversingDirectory( std::string_view file )
{
    fs::path currentPath{ file };
    std::vector<fs::directory_entry> dir_entries{};
    for( const auto & entry : fs::directory_iterator( currentPath ) )
    {
        dir_entries.push_back( entry );
    }

    // Partitioning the directory entries based on the type of file it is either directory or regular file
    std::partition( dir_entries.begin(), dir_entries.end(), []( const auto & entry ) { return entry.is_directory(); } );
    // Traversing according to the type of file
    for( const auto & dir_entry : dir_entries )
    {
        switch( const auto & p = dir_entry.path(); fs::status( p ).type() )
        {
            case fs::file_type::directory: std::cout << p << " is a directory\n"; break;
            case fs::file_type::regular: std::cout << p << " is a regular file\n"; break;
        }
    }
}

int main()
{
    TraversingDirectory( "/home/adi/Documents/cpp/cpp_learnings" );

    return 0;
}