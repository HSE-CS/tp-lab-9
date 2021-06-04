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

typedef std::condition_variable cv;

void bubble_sort_th(std::vector<std::string>&,
    std::function<bool(std::string, std::string)>,
    bool&, bool&, bool&, std::mutex&, cv&);

std::function<bool(std::string, std::string)> comp_1 = [](std::string a, std::string b) {return a > b; };

void print_vct(std::vector<std::string>&);

#endif  // INCLUDE_TASK2_H_

