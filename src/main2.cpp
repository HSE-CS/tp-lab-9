// Copyright 2021 valvarl

#include <string>
#include <thread>
#include "task2.cpp"


int main() {
    std::string arr_string[] = {"bbbb", "ff", "e", "ccc", "aa", "ddddddd"};
    std::mutex mtx;
    bool work = true;
    std::thread tA(bubble_sort<std::string, 6>,
            &arr_string, std::ref(comp), &work, std::ref(mtx));
    std::thread tB(step_print<std::string, 6>,
            &arr_string, &work, std::ref(mtx));
    tB.join();
    tA.join();

    return 0;
}
