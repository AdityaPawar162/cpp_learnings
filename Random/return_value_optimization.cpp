#include <iostream>
#include <vector>


class Sample{
    public:
    Sample(){std::cout << "Default Constructor \n";}
    Sample(const Sample &){std::cout << "Copy Constructor \n";}
    Sample(Sample &&) noexcept {std::cout << "Move Constructor \n";}
    ~Sample(){std::cout << "Destructor Called \n";}
};

Sample createSample()
{
    return Sample();
}

int main()
{
    std::cout << "Returning object through function\n";
    Sample obj = createSample();


    return 0;
}