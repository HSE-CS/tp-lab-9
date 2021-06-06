//Copyright 2021 Kris

#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <mutex>
#include "task1.cpp"

int main() {
    std::vector<std::string> v = {"kris", "peper", "salt",
        "lion", "qwerty", "ytrewq"};
    v = bubblesort(v, comp_1);
    print_mas(v);
    v = bubblesort(v, comp_2);
    print_mas(v);
    v = bubblesort(v, comp_3);
    print_mas(v);
    v = bubblesort(v, comp_4);
    print_mas(v);
    v = bubblesort(v, comp_5);
    print_mas(v);
}
