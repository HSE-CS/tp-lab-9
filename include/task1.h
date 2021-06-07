// Copyright 2021 Schenikova

#ifndef INCLUDE_TASK1_H_
#define INCLUDE_TASK1_H_
#include <iostream>
#include <vector>
#include <functional>
#include <string>

std::vector<std::string> BubbleSort(const std::vector<std::string>& array,
    std::function<bool(std::string, std::string)> comp);

void print(std::vector<std::string> arr);

#endif  //  INCLUDE_TASK1_H_
