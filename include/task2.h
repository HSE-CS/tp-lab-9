//  Copyright Baklanov 2021
#pragma once

#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <mutex>
#include <thread>

void bubblesort2(const std::vector<std::string>& vec,
    std::function<bool(std::string, std::string)> comparator);

void print(std::vector<std::string> v);
