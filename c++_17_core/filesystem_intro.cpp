#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

void UsingPath()
{
    fs::path selectedPath{ R"(/home/adi/Documents/cpp/cpp_learnings)" };

    // selectedPath.remove_filename();
    std::cout << "Selected path has " << selectedPath.filename() << " as filename\n";
    // selectedPath /= "new_file";
    std::cout << "Selected path: " << selectedPath.string() << '\n';

    if( selectedPath.has_root_path() )
        std::cout << "Root path: " << selectedPath.root_path() << '\n';

    if( selectedPath.has_parent_path() )
        std::cout << "Parent path: " << selectedPath.parent_path() << '\n';

    if( selectedPath.has_relative_path() )
        std::cout << "Relative path: " << selectedPath.relative_path() << '\n';

    if( selectedPath.has_filename() )
        std::cout << "Filename: " << selectedPath.filename() << '\n';

    if( selectedPath.has_stem() )
        std::cout << "Stem: " << selectedPath.stem() << '\n';
}

int main()
{
    UsingPath();
    return 0;
}