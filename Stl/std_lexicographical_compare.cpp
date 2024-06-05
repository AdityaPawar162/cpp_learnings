#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<char> seq1 = { 'a', 'b', 'c' };
    std::vector<char> seq2 = { 'a', 'b', 'd' };
    std::vector<char> seq3 = { 'a', 'b', 'c', 'd' };

    if(std::lexicographical_compare(std::begin(seq1),std::end(seq1),std::begin(seq2),std::end(seq2))){
        std::cout << "Sequence 1 is lexicographically less than sequence 2\n";
    }
    else{
        std::cout << "Sequence 1 is not lexicographically less than sequence 2\n";
    }
    if(std::lexicographical_compare(std::begin(seq1),std::end(seq1),std::begin(seq3),std::end(seq3)))
    {
        std::cout << "Sequence 1 is lexicographically less than sequence 3\n";
    }
    else{
        std::cout << "Sequence 1 is not lexicoographically less than sequence 3\n";
    }

    // For strings
    std::string str1 = "apple";
    std::string str2 = "banana";
    if(std::lexicographical_compare(std::begin(str1),std::end(str1),std::begin(str2),std::end(str2)))
    {
        std::cout << "String 1 is lexicographically less than string 2\n";
    }
    else{
        std::cout << "String 1 is not lexicographically less than string 2\n";
    }
}