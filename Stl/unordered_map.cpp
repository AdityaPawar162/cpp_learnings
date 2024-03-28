/*
 std::unordered_set stores values that act as keys for hashing, iterators are constant
*/
#include <iostream>
#include <unordered_map>

void unordered_map()
{
    std::unordered_map<std::string,std::string> coll;
    coll["Batman"] = "Bruce Wayne";
    coll["Superman"] = "Clark Kent";
    coll["Hulk"] = "Bruce Banner";
     for(const auto &x : coll)
     {
        std::cout << "Bucket #: " << coll.bucket(x.first) << " contains " << x.first << '\n';
     }
    
    std::cout << "Bucket count " << coll.bucket_count() << '\n';
    std::cout << "Number of elements " << coll.size() << '\n';
    std::cout << "Load Factor " << coll.load_factor() << '\n';  // Load factor is elements / number of capacity of hash table
 


}    
int main()
{
    unordered_map();
    return 0;
}

