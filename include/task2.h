// Copyright 2021 alexgiving

#ifndef INCLUDE_TASK2_H_
#define INCLUDE_TASK2_H_

#include <iostream>
#include <vector>
#include <string>
#include <mutex>
#include <condition_variable>

void bubbleSort(std::vector<std::string>& arr,
                bool comp(const std::string& s1, const std::string& s2));
void print(std::vector<std::string> const& arr);
void print(std::vector<std::string> const& arr, const std::string& sep);

#endif  // INCLUDE_TASK2_H_
