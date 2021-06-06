// Copyright 2021 kisozinov

#ifndef INCLUDE_TASK1_H_
#define INCLUDE_TASK1_H_

#include <functional>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

std::vector<std::string> bubbleSort(const std::vector<std::string> &vec,
    std::function<bool(std::string, std::string)> comparator);

void print(std::vector<std::string> vec);
#endif  // INCLUDE_TASK1_H_
