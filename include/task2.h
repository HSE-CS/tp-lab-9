// Copyright 2021 Egor Buzanov
#ifndef INCLUDE_TASK2_H_
#define INCLUDE_TASK2_H_

#include <condition_variable>
#include <functional>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

void threadBubbleSort(std::vector<std::string> *_array,
                      std::function<bool(std::string, std::string)> _comp);

void threadPrint(const std::vector<std::string> &_array);

#endif  // INCLUDE_TASK2_H_
