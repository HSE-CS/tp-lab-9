// Copyright 11.06.21 DenisKabanov

#include "task2.h"

void bubble(std::vector<std::string>& arr,
        bool comp(const std::string str1, const std::string str2)) {
    std::vector<std::string> copy(arr);
    std::mutex sync;
    std::size_t size_of_arr = copy.size();
    for (std::size_t i = 0; i < size_of_arr - 1; i++) {
        std::thread th([&copy, &comp, &sync, &i, &size_of_arr]() {
            for (std::size_t j = 0; j < size_of_arr - i - 1; j++) {
                if (comp(copy[j + 1], copy[j])) {
                sync.lock();
                std::string temp = copy[j];
                copy[j] = copy[j + 1];
                copy[j + 1] = temp;
                sync.unlock();
                }
            }
        });
        th.join();
        print(copy);
    }
}

void print(std::vector<std::string>& arr) {
    for (auto x : arr) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}
