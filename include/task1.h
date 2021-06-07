// Copyright Slavokeru 2021
#ifndef INCLUDE_TASK1_H_
#define INCLUDE_TASK1_H_
#include<vector>
#include<algorithm>
#include<functional>
#include<iostream>
#include<string>

void BS(std::vector<std::string>* vec,
  const std::function<bool(std::string, std::string)> comp);
#endif  //  INCLUDE_TASK1_H_
