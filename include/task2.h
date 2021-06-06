// Copyright 2021 LongaBonga
#ifndef INCLUDE_TASK2_H_
#define INCLUDE_TASK2_H_
#include <string>
#include <vector>
#include <iostream>
#include <functional>
#include <mutex>
#include <thread>

std::vector<std::string> bubbleSortParallel(std::vector<std::string>& vec, std::function<bool(std::string, std::string)> comparator);

#endif  //  INCLUDE_TASK2_H_
