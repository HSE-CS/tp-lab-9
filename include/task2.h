// Copyright 2021 kisozinov

#ifndef INCLUDE_TASK2_H
#define INCLUDE_TASK2_H

#include "task1.h"
#include <thread>
#include <mutex>

std::vector<std::string> bubbleSortTwoThread(const std::vector<std::string> &vec,
    std::function<bool(std::string, std::string)> comparator);

#endif //  INCLUDE_TASK2_H
