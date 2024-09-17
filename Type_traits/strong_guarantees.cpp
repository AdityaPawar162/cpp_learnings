#include <algorithm>
#include <iostream>
#include <memory>
#include <stdexcept>

template<typename T>
class CustomArray
{
public:
    explicit CustomArray( size_t size ) : size( size ), data( std::make_unique<T[]>( size ) )
    {
        std::fill( data.get(), data.get() + size, T() );
    }
    // Copy Constructor
    CustomArray( const CustomArray & other ) : size( other.size ), data( std::make_unique<T[]>( other.size ) )
    {
        safecopy( data.get(), other.data.get(), size );
    }

    // Move constructor
    CustomArray( CustomArray && other ) noexcept : size( size ), data( std::move( other.data ) )
    {
        other.size = 0;
    }

    // Copy assignment operator
    CustomArray & operator=( const CustomArray & other )
    {
        if( this != other )
        {
            std::unique_ptr<T[]> newData( std::make_unique<T[]>( other.size ) );
            safecopy( newData.get(), other.data.get(), other.size );
            size = other.size;
            data = std::move( newData );
        }
        return *this;
    }

    // Move assignment operator
    CustomArray & operator=( CustomArray && other ) noexcept
    {
        if( this != &other )
        {
            data       = std::move( other.data );
            size       = other.size;
            other.size = 0;
        }

        return *this;
    }

private:
    size_t size{ 0 };

    // RAII
    std::unique_ptr<T[]> data;

    void safecopy( T * destination, T * source, size_t size )
    {
        std::copy( source, source + size, destination );
    }
};

int main() {
  try {
    // CustomArray managing an array of 5 integers
    CustomArray<int> arr(5);
    // ... Use the array
  } catch (const std::exception &e) {
    std::cerr << "An exception occurred: " << e.what()
              << '\n';
    // CustomArray destructor will clean up resources if an
    // exception occurs
  }

  return 0;
}