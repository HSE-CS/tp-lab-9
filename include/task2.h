//  Copyright 2021 Nikita Naumov
#ifndef INCLUDE_TASK2_H_
#define INCLUDE_TASK2_H_

#include <iostream>
#include <string>
#include <functional>
#include <vector>
#include <ctime>
#include <thread>
#include <mutex>

void stringBubbleSortWithMutex(std::vector<std::string>& vector,
                            std::function<bool(std::string, std::string)> f);

void printVector(std::vector<std::string> vector);

#endif  //  INCLUDE_TASK2_H_
