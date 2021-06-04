//  Copyright 2021 Nikita Naumov
#include "../include/task2.h"

void insideSort(int iteration, std::vector<std::string>& vector, 
                std::function<bool(std::string, std::string)> f) {
    for (size_t i = 0; i < vector.size() - 1 - iteration; ++i) {
        if (f(vector[i], vector[i+1])) {
            std::swap(vector[i], vector[i+1]);
        }
    }
}

void printVector(std::vector<std::string>& vector, int iteration) {
    std::cout << "Current iteration -> " << iteration << std::endl;
    for (auto obj: vector) {
        std::cout << obj << std::endl;
    }
    std::cout << std::endl;
}

void stringBubbleSortWithMutex(std::vector<std::string>& vector, std::function<bool(std::string, std::string)> f) {
    std::mutex locker;
    for (size_t i = 0; i < vector.size(); ++i) {
        locker.lock();
        std::thread thread1(insideSort, i, std::ref(vector), f);
        locker.unlock();
        thread1.join();
        printVector(vector, i);
    }
}
