#include <iostream>
#include <thread>
#include <chrono>

void test(int x)
{   
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::thread::id this_id = std::this_thread::get_id();
    std::cout << "Hello from thread # " << this_id << " with arg = " << x << std::endl;
}

int main()
{
    auto lambda = [](int x) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::thread::id this_id = std::this_thread::get_id();
        std::cout << "Hello from thread # " << this_id << " with arg = " << x << std::endl;
    };
    
    std::thread t1(test, 1);
    std::thread t2(&test, 1);
    std::thread t3(lambda, 1);
    std::jthread t4(lambda, 2);

    t1.join();
    t2.join();
    t3.join();

    test(1);
    (&test)(1);
    lambda(1);

    std::cout << "Hello from the main thread.\n";
}