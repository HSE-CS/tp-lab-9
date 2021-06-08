// Copyright 2021 kisozinov

#ifndef INCLUDE_TASK2_H_
#define INCLUDE_TASK2_H_

#include <thread>
#include <mutex>
#include <string>
#include "task1.h"

std::vector<std::string> bubbleSortTwoThread(
    const std::vector<std::string> &vec,
    std::function<bool(std::string, std::string)> comparator);

#endif  // INCLUDE_TASK2_H_
