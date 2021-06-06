// Copyright 2021 Egor Buzanov
#ifndef INCLUDE_TASK1_H_
#define INCLUDE_TASK1_H_

#include <functional>
#include <iostream>
#include <string>
#include <vector>

void bubbleSort(std::vector<std::string> *_array,
                std::function<bool(std::string, std::string)> _comp);

void print(const std::vector<std::string> &_array);

#endif  // INCLUDE_TASK1_H_
