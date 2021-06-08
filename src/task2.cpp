// Copyright 2021 Rogov Andrey

#include "task2.h"

std::mutex mut;

void sort(std::vector<std::string> arr,
    std::function<bool(std::string, std::string)> comp, int i) {
    for (int j = 0; j < arr.size() - i - 1; j++) {
        if (comp(arr[j], arr[j + 1])) {
            mut.lock();
            std::swap(arr[j], arr[j + 1]);
            mut.unlock();
        }
    }
}


void BigBubbleSort(const std::vector<std::string>& array,
    std::function<bool(std::string, std::string)> comp) {
    std::vector<std::string> arr(array);
    for (int i = 0; i < arr.size() - 1; i++) {
        std::thread thread_1(sort, arr, comp, i);
        thread_1.join();
        print(arr);
    }
}


void print(std::vector<std::string> words) {
    for (std::string a : words) {
        std::cout << a << " ";
    }
    std::cout << std::endl << std::endl;
}
