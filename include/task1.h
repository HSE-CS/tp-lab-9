// Copyright 2021 S
#ifndef INCLUDE_TASK1_H_
#define INCLUDE_TASK1_H_
#include <string>
#include <vector>
#include <functional>
#include <iostream>

std::vector<std::string> bubbleSort(const std::vector<std::string>& vector,
        std::function<bool(std::string, std::string)> comp);

void print(const std::vector<std::string>& vector);


#endif  //  INCLUDE_TASK1_H_
