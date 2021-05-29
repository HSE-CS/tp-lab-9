#pragma once

#include <iostream>
#include <vector>
#include <functional>
#include <string>

void bubblesort2(std::vector<std::string>& v,
    std::function<bool(std::string, std::string)> comparator);

void print(std::vector<std::string> v);