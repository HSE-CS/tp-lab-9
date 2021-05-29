#include "task1.h"
#include "task2.h"
#include "task3.h"
#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <mutex>

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
    bubblesort2(v, [](std::string a, std::string b)
        {return a.length() > b.length(); });
}