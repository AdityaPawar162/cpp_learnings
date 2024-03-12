#include<iostream>
#include<thread>
#include<vector>
#include<future>

static int shared_value = 0;

// auto lambda=[](int x)
// {
//     std::cout << "Hello from thread" << std::this_thread::get_id() << std::endl;
//     std::cout << "Arguments passed in :" << std::endl;
    
// };

// void shared_value_increment()
// {
//     shared_value += 1;
// }

int square(int x)
{
    return x*x;
}

int main()
{
    // std::vector<std::thread> threads;
    // for (int i = 0; i < 10; i++)
    // {
    //     threads.push_back(std::thread(shared_value));
    // }
    // for (int i = 0; i < 10; i++)
    // {
    //     threads[i].join();
    // }



    std::future<int> asyncFunction = std::async(&square,12);
    for (int i = 0; i < 10; i++)
    {
        std::cout << square(i) << std::endl;
    }
    
    int result = asyncFunction.get();
    std::cout << "result is: " << result << std::endl;
    
    // std::thread myThread(&test, 10);
    // myThread.join();
    // std::cout << "Shared Valuew " << shared_value << std::endl;
    
    return 0;
}