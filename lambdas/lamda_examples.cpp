#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

/*
Create lambda expressions & their equivalent function objects for the following functions.

1.T Max(T, T); //Return largest element
2.bool Greater(T, T) ; //Return true if first argument is greater than the second
3.bool Less(T, T) ; //Return true if first argument is less than the second
4.pair<T,T> MinMax(ItrBegin, ItrEnd) ;//Accept iterators of any container and return the largest and smallest element
from that container.
*/

// 1.T Max(T, T); //Return largest element
/*template <typename T, typename Callback>
T Max(T a, T b, Callback cmp) {
    return cmp(a, b) ? a : b;
}

int main()
{
    int x = 5;
    int y = 6;
    auto max = [](auto a,auto b){return a > b;};
    std::cout << Max(x,y,max) << std::endl;

}*/

// 2.bool Greater(T, T) ; //Return true if first argument is greater than the second
/*template <typename T, typename Callback>
bool Greater(T a, T b, Callback cmp) {
    return cmp(a, b) ? a : b;
}

int main()
{
    int x = 5;
    int y = 6;
    auto max = [](auto a,auto b){return a > b;};
    std::cout << Greater(x,y,max) << std::endl;

}*/

// 4.pair<T,T> MinMax(ItrBegin, ItrEnd) ;//Accept iterators of any container and return the largest and smallest element
// from that container.

template<typename Iterator>
auto MinMax( Iterator begin, Iterator end )
{
    if( begin == end )
        return std::make_pair( *begin, *end );

    auto min_element = *std::min_element( begin, end );
    auto max_element = *std::max_element( begin, end );

    return std::make_pair( min_element, max_element );
}

int main()
{
    std::vector<int> numbers = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5 };
    auto result              = MinMax( numbers.begin(), numbers.end() );

    std::cout << "Minimum element: " << result.first << std::endl;
    std::cout << "Maximum element: " << result.second << std::endl;
}