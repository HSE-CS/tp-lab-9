//Copyright 2021 Kris


#ifndef INCLUDE_TASK2_H_
#define INCLUDE_TASK2_H_

#include <iostream>
#include <vector>
#include <functional>
#include <string>

std::function<bool(std::string, std::string)> comp_12 =
[](std::string a, std::string b) {return a > b; };

std::vector<std::string> bubblesort22(const std::vector<std::string>& vec,
    std::function<bool(std::string, std::string)> comparator) {
    std::vector<std::string> v(vec);
    for (unsigned int i = 0; i < v.size() - 1; ++i) {
        for (unsigned int j = 0; j < v.size() - i - 1; ++j) {
            if (comparator(v[j], v[j + 1])) {
                std::string temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
    return v;
}

#endif  //  INCLUDE_TASK2_H_
