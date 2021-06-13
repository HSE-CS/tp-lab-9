// Copyright 2021 S
#ifndef INCLUDE_TASK2_H_
#define INCLUDE_TASK2_H_
#include <thread>
#include <functional>
#include <vector>
#include <mutex>
#include <iostream>
#include <string>

void bubbleSortThreaded(const std::vector<std::string>& vector,
        std::function<bool(std::string, std::string)> comp);

void print(const std::vector<std::string>& vector);

#endif  //  INCLUDE_TASK2_H_
