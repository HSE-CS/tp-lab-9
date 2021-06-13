// Copyright 11.06.21 DenisKabanov

#ifndef INCLUDE_TASK2_H_
#define INCLUDE_TASK2_H_

#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>

void bubble(std::vector<std::string>& arr,
        bool comp(const std::string str1, const std::string str2));

void print(std::vector<std::string>& arr);

#endif  //  INCLUDE_TASK2_H_
