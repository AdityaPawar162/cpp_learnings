/* Implemented as binary tree,stores a pair that contains a key and value, elements are stored in sorted order based on a key, elements are stored in sorted order based on a key
 Map is not for handling duplicate keys but multimap is.
*/

#include <iostream>
#include <map>

void Map()
{
    
    std::map<int,std::string> m{
        {1,"Superman"},
        {2,"Batman"},
        {3,"Green Lantern"}   // First way of inserting values in map
    };
    
    m.insert(std::pair<int,std::string>(8,"Aquaman")); // Second way of inserting value in map
    
    m.insert(std::make_pair(6,"Wonder woman")); // Third way of inserting value in map
    
    m[0] = "Flash"; // Fourth way of inserting values in map

    for(auto const &x : m)
    {
        std::cout  << x.first << " " << x.second << std::endl;
    }
    
  auto  itr =  m.find(1);
  std::cout << itr->second << std::endl; // Prints the value present at the key specified to itr
}

int main()
{
    Map();

    return 0;
}