#pragma once

#include <iostream>
#include <vector>
#include <functional>
#include <string>

void bubblesort(std::vector<std::string>& v,
    std::function<bool(std::string, std::string)> comparator);