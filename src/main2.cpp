//Copyright 2021 Kris


#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <mutex>
#include "task2.cpp"

void print_mas(std::vector<std::string> v) {
    for (std::string a : v) {
        std::cout << "\"" << a << "\"" << ", ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<std::string> v = { "kris", "peper", "salt",
        "lion", "qwerty", "ytrewq" };
    v = bubblesort22(v, comp_12);
    print_mas(v);
}
