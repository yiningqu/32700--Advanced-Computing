#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>




int main() {
    int balance = 0;
    std::mutex m;


    std::thread t1([&]() {
        for (int i = 0; i < 10000000; i++) {
            m.lock();
            balance++;
            m.unlock();
        }
    });

    std::thread t2([&]() {
        for (int i = 0; i < 10000000; i++) {
            m.lock();
            balance--;
            m.unlock();
        }
    });

    t1.join();
    t2.join();

    std::cout << "Final balance: " << balance << std::endl;

    return 0;
}
