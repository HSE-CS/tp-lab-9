// Copyright 2021 S
#include <algorithm>
#include "task1.h"

int main() {
    std::vector<std::string> exampleStrings = {"ab", "aa", "ba", "bc"};
    std::function<bool(std::string, std::string)> comp_1 =
            [](std::string str1, std::string str2){ return str1[0] < str2[0]; };
    exampleStrings = bubbleSort(exampleStrings, comp_1);
    print(exampleStrings);
    std::function<bool(std::string, std::string)> comp_2 =
            [](std::string str1, std::string str2) {
        return str1.back() < str2.back(); };
    exampleStrings = bubbleSort(exampleStrings, comp_2);
    print(exampleStrings);
    std::function<bool(std::string, std::string)> comp_3 =
            [](std::string str1, std::string str2) {
        return str1[str1.size() / 2] < str2[str2.size() / 2];
    };
    exampleStrings = bubbleSort(exampleStrings, comp_3);
    print(exampleStrings);
    std::function<bool(std::string, std::string)> comp_4 =
            [](std::string str1, std::string str2) {
        return str1.size() < str2.size(); };
    exampleStrings = bubbleSort(exampleStrings, comp_4);
    print(exampleStrings);
    std::function<bool(std::string, std::string)> comp_5 =
            [](std::string str1, std::string str2) { return str1 < str2; };
    exampleStrings = bubbleSort(exampleStrings, comp_5);
    print(exampleStrings);
    return 0;
}
