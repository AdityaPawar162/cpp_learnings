#include <cstring>
#include <iostream>

class RuleOfFive
{
private:
    char * data_;

public:
    RuleOfFive( const char * data = "" )
    {
        data_ = new char[std::strlen( data ) + 1];
        std::strcpy( data_, data );
        std::cout << "Constructor called for " << data_ << std::endl;
    }

    ~RuleOfFive()
    {
        delete[] data_;
        std::cout << "Destructor called for " << data_ << std::endl;
    }

    // Copy Constructor
    RuleOfFive( const RuleOfFive & other )
    {
        data_ = new char[std::strlen( other.data_ ) + 1];
        std::strcpy( data_, other.data_ );
        std::cout << "Copy Constructor called for " << data_ << std::endl;
    }

    // Copy Assignment Operator
    RuleOfFive & operator=( const RuleOfFive & other )
    {
        if( this == &other )
            return *this; // Self Assignment

        delete[] data_;                                   // Free the existing resource
        data_ = new char[std::strlen( other.data_ ) + 1]; // Allocate new resource
        std::strcpy( data_, other.data_ );
        std::cout << "Copy Assignment Operator called for " << data_ << std::endl;
        return *this;
    }

    // Move constructor
    RuleOfFive( RuleOfFive && other ) noexcept
    {
        data_       = other.data_;
        other.data_ = nullptr;
        std::cout << "Move Constructor called for " << data_ << std::endl;
    }

    // Move Assignment Operator
    RuleOfFive & operator=( RuleOfFive && other ) noexcept
    {
        if( this == &other ) // Self Assignment
            return *this;
        data_       = other.data_;
        other.data_ = nullptr;
        std::cout << "Move Assignment Operator called for " << data_ << std::endl;
        return *this;
    }

    void Print()
    {
        std::cout << data_ << std::endl;
    }
};

int main()
{
    RuleOfFive obj{ "Hello" };
    RuleOfFive obj2 = obj; // Copy Constructor
    RuleOfFive obj3;
    obj3 = obj; // Copy Assignment Operator

    RuleOfFive obj4 = std::move( obj ); // Move Constructor
    RuleOfFive obj5;
    obj5 = std::move( obj2 ); // Move Assignment Operator

    obj3.Print();
    obj4.Print();
    obj5.Print();
    return 0;
}