// Copyright 2021 Bogomazov

#ifndef INCLUDE_TASK1_H_
#define INCLUDE_TASK1_H_

#include <string>
#include <vector>
#include <utility>
#include <iterator>
#include <iostream>
#include <functional>

std::function<bool(std::string, std::string)> comp_f = [](std::string a,
    std::string b) {
    return a > b;
};

std::function<bool(std::string, std::string)> comp_s = [](std::string a,
    std::string b) {
    int count_a = 0;
    int count_b = 0;
    for (long unsigned int i = 0; i < a.size(); ++i)
        if (a[i] >= 'A' && a[i] <= 'Z')
            count_a++;
    for (long unsigned int i = 0; i < b.size(); ++i)
        if (b[i] >= 'A' && b[i] <= 'Z')
            count_b++;
    if (count_a < count_b) {
        return true;
    } else {
        return false;
    }
};

std::function<bool(std::string, std::string)> comp_th = [](std::string a,
    std::string b) {
    int count_a = 0;
    int count_b = 0;
    for (int64_t i = 0; i < a.size(); ++i)
        if (a[i] == 'a' || a[i] == 'A')
            count_a++;
    for (int64_t i = 0; i < b.size(); ++i) if (b[i] == 'a' || b[i] == 'A')
        count_b++;
    if (count_a < count_b) {
        return true;
    } else {
        return false;
    }
};

std::function<bool(std::string, std::string)> comp_fo = [](std::string a,
    std::string b) {
    if (a.back() > b.back()) {
        return true;
    } else {
        return false;
    }
};

std::function<bool(std::string, std::string)> comp_fi = [](std::string a,
    std::string b) {
    if (a.size() > b.size()) {
        return true;
    } else {
        return false;
    }
};

void bubbleSort(std::vector<std::string>& vect,
    std::function<bool(std::string, std::string)> comp);

template<class T>
void bubbleSortT(std::vector<std::string>& vect, T comp);

void print_vct(std::vector<std::string>);

#endif  // INCLUDE_TASK1_H_
