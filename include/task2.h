// Copyright 2021 FOM
#ifndef INCLUDE_TASK2_H_
#define INCLUDE_TASK2_H_


#include <iostream>
#include <vector>
#include <string>
#include <mutex>
#include <condition_variable>

void BubbleSortParrallel(std::vector<std::string>& vector_,
    bool comp(const std::string& first_, const std::string& second_));
void printresult(std::vector<std::string> const& arr);
#endif  //  INCLUDE_TASK2_H_
