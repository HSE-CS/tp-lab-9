// Copyright 2021 SoDa

#include "task2.h"

std::mutex mtx;
cv con_var;
bool step = false;
bool printed = true;
bool sorted = false;

int main() {
    std::vector<std::string> mass_original;
    mass_original.push_back(std::string("Aboba"));
    mass_original.push_back(std::string("SeRg"));
    mass_original.push_back(std::string("hello_world"));
    mass_original.push_back(std::string("Final"));
    mass_original.push_back(std::string("GoD_JoB"));
    mass_original.push_back(std::string("12"));
    mass_original.push_back(std::string("tb-lab-9"));

    std::thread t_1(bubble_sort_th, std::ref(mass_original), comp_1);

    while (!sorted) {
        std::unique_lock<std::mutex> unqLock(mtx);
        con_var.wait(unqLock, []() { return step; });
        print_vct(mass_original);
        printed = true;
        step = false;
        unqLock.unlock();
        con_var.notify_all();
    }
    t_1.join();
    return 0;
}
