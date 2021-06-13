// Copyright 2021 Bogomazov

#include "../include/task_second.h"

void bubbleSortTh(std::vector<std::string>& vect,
    std::function<bool(const std::string&, const std::string&)> comp) {
    extern bool printed;
    extern bool sorted;
    extern bool step;
    extern std::mutex mutexObj;
    extern cv conVar;
    int size = vect.size();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            std::unique_lock<std::mutex> unqLock(mutexObj);
            conVar.wait(unqLock, []() { return printed; });
            if (comp(vect[j + 1], vect[j])) {
                std::swap(vect[j], vect[j + 1]);
            }
            step = true;
            printed = false;
            unqLock.unlock();
            conVar.notify_all();
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
