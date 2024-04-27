#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

void Alloc()
{
    int *p = (int*)malloc(sizeof(int));
    if( p!= nullptr)
    {
        *p = 50;
        free(p);
    }// The scope of p is required to be only in the above if block, but we are able to access it outside this if block.

    // To compensate this c++ 17 has add the initialisation along with if block 
    // if(initialisation;condition)

    if(int *p = (int*)malloc(sizeof(int));p!= nullptr)
    {
        *p = 50;
        free(p);

    }
    else{
        // Here p will be nullptr
    }

}

void Write(const std::string &data)
{
    
    if(std::ofstream out{"d"};out && !data.empty())
    {
        
            std::cout << "Writing data to file\n";
            out << data;
    }  
    else
    {
        std::cout << "Error in writing data to file\n";
        out << "####";
    }
    
}

int main()
{
    std::string file{"s"};

    Write(file);
    
    return 0;
}