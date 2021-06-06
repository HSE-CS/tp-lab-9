// Copyright 2021 me
#ifndef INCLUDE_TASK2_H_
#define INCLUDE_TASK2_H_

#include<vector>
#include<string>
#include<thread>
#include<functional>
#include<mutex>
#include<chrono>


void task2(std::vector<std::string> &toSort,
           std::function<bool(std::string, std::string)> &comp, bool &isWork,
           std::mutex &mtx);

void print_vector(std::vector<std::string> &toPrint, bool &isWork,
                  std::mutex &mtx);

#endif  // INCLUDE_TASK2_H_
