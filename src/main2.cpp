// Copyright 2021 Bogomazov

#include "../include/task2.h"

std::mutex mutexObj;
cv conVar;
bool step = false;
bool printed = true;
bool sorted = false;

std::function<bool(const std::string&,
    const std::string&)> comp_1 = [](const std::string& a,
        const std::string& b) {
    return a > b;
};

int main() {
    std::vector<std::string> mass_original;
    mass_original.push_back(std::string("Class"));
    mass_original.push_back(std::string("Testus"));
    mass_original.push_back(std::string("hello_world"));
    mass_original.push_back(std::string("88005553535"));
    mass_original.push_back(std::string("jija"));

    std::thread t_1(bubbleSortTh, std::ref(mass_original), comp_1);

    while (!sorted) {
        std::unique_lock<std::mutex> unqLock(mutexObj);
        conVar.wait(unqLock, []() { return step; });
        print_vct(mass_original);
        printed = true;
        step = false;
        unqLock.unlock();
        conVar.notify_all();
    }
    t_1.join();
    return 0;
}
