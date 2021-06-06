// Copyright NikDemoShow 2021
#ifndef INCLUDE_TASK1_H_
#define INCLUDE_TASK1_H_
#include<vector>
#include<functional>
#include<iostream>
#include<string>
#include<algorithm>

void Bsort(std::vector<std::string>* objects,
  const std::function<bool(std::string, std::string)> comp);
#endif  //  INCLUDE_TASK1_H_
