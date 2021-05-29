//  Copyright Baklanov 2021
#pragma once

#include <iostream>
#include <vector>
#include <functional>
#include <string>

std::vector<std::string> bubblesort(const std::vector<std::string>& vec,
    std::function<bool(std::string, std::string)> comparator);
