// Copyright Slavokeru 2021
#ifndef INCLUDE_TASK2_H_
#define INCLUDE_TASK2_H_
#include<condition_variable>
#include<algorithm>
#include<mutex>
#include<string>
#include<thread>
#include<vector>
#include<functional>
#include<iostream>


void BS(std::vector<std::string>* vec,
  const std::function<bool(std::string, std::string)> comp,
  bool* srt, std::mutex* m,
  std::condition_variable* c);
#endif  //  INCLUDE_TASK2_H_
