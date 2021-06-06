// Copyright NikDemoShow 2021
#ifndef INCLUDE_TASK2_H_
#define INCLUDE_TASK2_H_
#include<vector>
#include<functional>
#include<iostream>
#include<condition_variable>
#include<algorithm>
#include<iostream>
#include<thread>
#include<mutex>
#include<string>

void Bsort(std::vector<std::string>& objects,
  const std::function<bool(std::string, std::string)> comp,
  bool& done, std::mutex& mu,
  std::condition_variable& cv);
#endif  //  INCLUDE_TASK2_H_
