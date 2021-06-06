// Copyright 2021 SoDa

#include "task2.h"

void bubble_sort_th(std::vector<std::string>& vect,
    std::function<bool(const std::string&, const std::string&)> comp) {
    extern bool printed;
    extern bool sorted;
    extern bool step;
    extern std::mutex mtx;
    extern cv con_var;
    int size = vect.size();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            std::unique_lock<std::mutex> unqLock(mtx);
            con_var.wait(unqLock, []() { return printed; });
            if (comp(vect[j + 1], vect[j])) {
                std::swap(vect[j], vect[j + 1]);
            }
            step = true;
            printed = false;
            unqLock.unlock();
            con_var.notify_all();
        }
    }
    sorted = true;
}

void print_vct(std::vector<std::string> vct) {
    for (auto x : vct) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}
