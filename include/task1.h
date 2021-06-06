//  Copyright 2021 Nikita Naumov
#ifndef INCLUDE_TASK1_H_
#define INCLUDE_TASK1_H_

#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <ctime>

void stringBubbleSort(std::vector<std::string>& strVector,
                      std::function<bool(std::string, std::string)> f);

void printVector(std::vector<std::string> vector);

#endif  //  INCLUDE_TASK1_H_
