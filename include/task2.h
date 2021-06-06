// Copyright 2021 Soda

#ifndef INCLUDE_TASK2_H_
#define INCLUDE_TASK2_H_

#include <string>
#include <vector>
#include <iterator>
#include <iostream>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <utility>


typedef std::condition_variable cv;

void bubble_sort_th(std::vector<std::string>&,
    std::function<bool(const std::string&, const std::string&)>);

std::function<bool(const std::string&, const std::string&)> comp_1 = [](const std::string& a,
    const std::string& b) { return a > b; };

void print_vct(std::vector<std::string>);

#endif  // INCLUDE_TASK2_H_
