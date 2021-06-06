// Copyright 2021 me
#ifndef INCLUDE_TASK1_H_
#define INCLUDE_TASK1_H_

#include <functional>
#include <string>
#include <vector>
#include<iostream>

void bubble_sort(std::vector<std::string> &toSort,
                 std::function<bool(std::string, std::string)> comp);

void print_vector(std::vector<std::string> &toPrint);


#endif  // INCLUDE_TASK1_H_
