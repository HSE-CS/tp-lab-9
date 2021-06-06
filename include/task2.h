// Copyright 2021 DB
#ifndef INCLUDE_TASK2_H_
#define INCLUDE_TASK2_H_

#include <string>
#include <vector>
#include <iostream>
#include <mutex>

void BSort(std::vector<std::string>& arr,
                bool comp(const std::string s1, const std::string s2));
void print(std::vector<std::string>& arr);
#endif  //  INCLUDE_TASK2_H_
