//  Copyright Baklanov 2021
#pragma once

#include <iostream>
#include <vector>
#include <functional>
#include <string>

void bubblesort(const std::vector<std::string>& vec,
    std::function<bool(std::string, std::string)> comparator);
