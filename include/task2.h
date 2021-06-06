// Copyright 2021 LongaBonga
#ifndef INCLUDE_TASK2_H_
#define INCLUDE_TASK2_H_
#include <functional>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

void bubbleSortParallel(
    const std::vector<std::string>& vec,
    std::function<bool(std::string, std::string)> comparator);

void print(const std::vector<std::string>& vec);

#endif  //  INCLUDE_TASK2_H_
