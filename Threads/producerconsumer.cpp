#include <condition_variable>
#include <mutex>
#include <thread>
#include <iostream>
#include <queue>
#include <chrono>

int main()
{
    std::queue<int> produced_nums;
    std::mutex m;
    std::condition_variable cond_var;
    bool done = false;
    bool notified = false;

    std::thread producer([&]() {
        for (int i = 0; i < 5; ++i) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::lock_guard<std::mutex> lock(m);
            std::cout << "producing " << i << '\n';
            produced_nums.push(i);
            notified = true;
            cond_var.notify_one();
        }   

        std::lock_guard<std::mutex> lock(m);  
        notified = true;
        done = true;
        cond_var.notify_one();
    }); 

    std::thread consumer([&]() {
        while (!done) {
            std::unique_lock<std::mutex> lock(m);
            while (!notified) {  // loop to avoid spurious wakeups
                cond_var.wait(lock);
            }   
            while (!produced_nums.empty()) {
                std::cout << "consuming " << produced_nums.front() << '\n';
                produced_nums.pop();
            }   
            notified = false;
        }   
    }); 

    producer.join();
    consumer.join();
}
