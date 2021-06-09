// Copyright 2021 Vadukk
#include "task1.h"

int main() {
    std::vector<std::string> vec = { "hello", "book", "language" };
    bubbleSort(vec, [](std::string& s1, std::string& s2) {
        return s1 < s2; });
    bubbleSort(vec, [](std::string& s1, std::string& s2) {
        return s1.size() < s2.size(); });

    bubbleSort(vec, [](std::string& s1, std::string& s2) {
        return s1[s1.size()-1] < s2[s2.size()-1]; });

    bubbleSort(vec, [](std::string& s1, std::string& s2) {
        return s1[0] < s2[0]; });
    for (auto x : vec) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
    bubbleSort(vec, [](std::string& s1, std::string& s2) {
        return s1[s1.size() - 2] < s2[s2.size() - 2]; });
    return 0;
}