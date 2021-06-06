// Copyright 2021 LongaBonga
#ifndef INCLUDE_TASK1_H_
#define INCLUDE_TASK1_H_
#include <functional>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> bubbleSort(
    std::vector<std::string>& vec,
    std::function<bool(std::string, std::string)> comparator);

void print(std::vector<std::string>& vec);
#endif  //  INCLUDE_TASK1_H_
