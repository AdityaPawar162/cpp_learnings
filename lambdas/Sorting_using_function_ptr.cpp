#include <iostream>

// using Comparator = bool(*)(int,int);
template<typename T, int size, typename Comparator>
void Sort( T ( &arr )[size], Comparator comp )
{
    for( int i = 0; i < size - 1; ++i )
    {
        for( int j = 0; j < size - 1; ++j )
        {
            if( comp( arr[j], arr[j + 1] ) )
            {
                T temp     = std::move( arr[j] );
                arr[j]     = std::move( arr[j + 1] );
                arr[j + 1] = std::move( temp );
            }
        }
    }
}

bool comp( int x, int y )
{
    return x > y;
}

bool comp1( int x, int y )
{
    return x < y;
}

auto main() -> int
{
    int arr[]{ 1, 6, 8, 4, 0 };
    for( auto x : arr )
        std::cout << x << " ";

    std::cout << '\n';

    Sort( arr, comp1 );

    for( auto x : arr )
        std::cout << x << " ";

    std::cout << '\n';
}