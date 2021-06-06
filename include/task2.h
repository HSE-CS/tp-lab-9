// Copyright 2021 GN
#ifndef INCLUDE_TASK2_H_
#define INCLUDE_TASK2_H_

#include <iostream>
#include <vector>
#include <string>
#include <mutex>

void BubbleSort(std::vector<std::string>& arr,
    bool comp(const std::string s1, const std::string s2));
void print(std::vector<std::string>& arr);
#endif  //  INCLUDE_TASK2_H_
