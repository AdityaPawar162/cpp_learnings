#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;
// Shows the permissions of a file
void demo_perms( fs::perms p )
{
    std::cout << ( ( p & fs::perms::owner_read ) != fs::perms::none ? "r" : "-" )
              << ( ( p & fs::perms::owner_write ) != fs::perms::none ? "w" : "-" )
              << ( ( p & fs::perms::owner_exec ) != fs::perms::none ? "x" : "-" )
              << ( ( p & fs::perms::group_read ) != fs::perms::none ? "r" : "-" )
              << ( ( p & fs::perms::group_write ) != fs::perms::none ? "w" : "-" )
              << ( ( p & fs::perms::group_exec ) != fs::perms::none ? "x" : "-" )
              << ( ( p & fs::perms::others_read ) != fs::perms::none ? "r" : "-" )
              << ( ( p & fs::perms::others_write ) != fs::perms::none ? "w" : "-" )
              << ( ( p & fs::perms::others_exec ) != fs::perms::none ? "x" : "-" ) << '\n';
}

void FilePermissions( std::string_view file )
{
    fs::path currentPath{ file };
    if( !fs::exists( currentPath ) )
    {
        std::cerr << "Path does not exist" << file << '\n';
        return;
    }
    auto perm = fs::status( currentPath ).permissions();
    std::cout << "Permissions of " << currentPath << " are: ";
    demo_perms( perm );
    std::cout << "Changing permissions\n";
    fs::permissions( currentPath, fs::perms::owner_all, fs::perm_options::add );
    perm = fs::status( currentPath ).permissions();
    demo_perms( perm );
}

int main()
{

    FilePermissions( "/home/adi/Documents/cpp/cpp_learnings/README.md" );

    return 0;
}