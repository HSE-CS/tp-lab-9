// Copyright 2021 Kuznetsov Mikhail
#ifndef INCLUDE_TASK2_H_
#define INCLUDE_TASK2_H_

#include <iostream>
#include <vector>
#include <string>
#include <mutex>
#include <condition_variable>

void simpleBubbleSort(std::vector<std::string> &_arr,
              bool _comp(const std::string &_x, const std::string &_y));
void printVectStr(std::vector<std::string> &_arr);
#endif  //  INCLUDE_TASK2_H_
