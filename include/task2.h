// Copyright 2021 Rogov Andrey

#ifndef INCLUDE_TASK2_H_
#define INCLUDE_TASK2_H_

#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <algorithm>

void sort(std::vector<std::string> arr,
    std::function<bool(std::string, std::string)> comp, int i);

void BigBubbleSort(const std::vector<std::string>& array,
    std::function<bool(std::string, std::string)> comp);

void print(std::vector<std::string> arr);

#endif  //  INCLUDE_TASK2_H_
