// Copyright 2021 FOM

#include "task2.h"
#include <thread>

void BubbleSortParrallel(std::vector<std::string>& vector_,
    bool comp(const std::string& first_, const std::string& second_)) {
    std::vector<std::string> vector(vector_);
    std::mutex a;
    for (int i = 0; i < vector.size() - 1; i++) {
        std::thread th([&vector, &comp, &a, &i]() {
            for (int j = 0; j < vector.size() - i - 1; ++j)
                if (comp(vector[j + 1], vector[j])) {
                    a.lock();
                    std::swap(vector[j], vector[j + 1]);
                    a.unlock();
                }
            });
        th.join();
        printresult(vector);
    }
}

void printresult(std::vector<std::string> const& arr) {
    for (const auto& num : arr)
        std::cout << num << ' ';
    std::cout << std::endl;
}
