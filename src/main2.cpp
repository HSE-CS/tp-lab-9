// Copyright 2021 S
#include <algorithm>

#include "task1.h"
#include "task2.h"

int main() {
    std::vector<std::string> exampleStrings = {"ab", "aa", "ba", "bc"};
    std::function<bool(std::string, std::string)> comp_1 =
            [](std::string str1, std::string str2) {
        return str1[0] < str2[0]; };
    bubbleSortThreaded(exampleStrings, comp_1);
}
