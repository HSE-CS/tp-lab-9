//  Copyright 2021 by Kartseva Masha
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>
#define TASK2_H
#ifdef TASK2_H

void BubbleSort(const std::vector<std::string>& arr,
bool comparator(const std::string& a, const std::string& b));

#endif  //  TASK2_H
