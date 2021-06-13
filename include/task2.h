// Copyright 2021 Bogomazov

#ifndef INCLUDE_TASK2_H_
#define INCLUDE_TASK2_H_

#include <mutex>
#include <string>
#include <vector>
#include <thread>
#include <utility>
#include <iterator>
#include <iostream>
#include <functional>
#include <condition_variable>


typedef std::condition_variable cv;

void bubbleSortTh(std::vector<std::string>&,
    std::function<bool(const std::string&, const std::string&)>);

void print_vct(std::vector<std::string>);

#endif  // INCLUDE_TASK2_H_
