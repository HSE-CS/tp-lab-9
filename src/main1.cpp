//  Copyright Baklanov 2021
#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <mutex>
#include "task1.cpp"
#include "task2.cpp"
#include "task3.cpp"

void printsorted(std::vector<std::string> v) {
    std::cout << "{ ";
    for (std::string a : v) {
        std::cout << "\"" << a << "\"" << ", ";
    }
    std::cout << " }" << std::endl;
}

int main() {
    std::vector<std::string> v = { "milk",
        "orange",
        "bread", "meat", "fish" };

    v = bubblesort(v, [](std::string a, std::string b)
        {return a.length() > b.length(); });
    printsorted(v);
}
