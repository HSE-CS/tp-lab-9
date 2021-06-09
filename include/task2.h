//  Copyright 2021 GHA created by Klykov Anton

#ifndef INCLUDE_TASK2_H_
#define INCLUDE_TASK2_H_

#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <cstring>
#include <mutex>
#include <thread>
#include <condition_variable>

void bubble_sort(std::vector<std::string>& vector_string,
                 std::function<bool(std::string,
                     std::string)> lambda_function);

#endif  // INCLUDE_TASK2_H_
