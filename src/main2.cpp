// Copyright 2021 VA
#include "task2.h"
#include <vector>
#include <thread>

int main() {
    std::vector<std::string> arr = { "gggg", "aaaa", "lllll", "bbbbbb", "pppppppp", "dddddd" };
    Sort2(arr, [](std::string a, std::string b) { return a > b; });
    printArr(arr);
    std::vector<std::string> arr = { "gggg", "aaaa", "lllll", "bbbbbb", "pppppppp", "dddddd" };
    std::function<bool(std::string, std::string)>  comp = [](std::string a, std::string b) { return a > b; };
    std::thread th1(Sort2, arr, comp);
    std::thread th2(Sort2, arr, comp);
    std::thread th3(Sort2, arr, comp);
    th1.join();
    th2.join();
    th3.join();
}
