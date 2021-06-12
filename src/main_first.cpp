// Copyright 2021 Bogomazov

#include "../include/task_first.h"

std::function<bool(std::string, std::string)> comp_f = [](std::string a,
    std::string b) {
    return a > b;
};

std::function<bool(std::string, std::string)> comp_s = [](std::string a,
    std::string b) {
    int count_a = 0;
    int count_b = 0;
    for (int64_t i = 0; i < static_cast<int64_t>(a.size()); ++i)
        if (a[i] >= 'A' && a[i] <= 'Z')
            count_a++;
    for (int64_t i = 0; i < static_cast<int64_t>(b.size()); ++i)
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
    for (int64_t i = 0; i < static_cast<int64_t>(a.size()); ++i)
        if (a[i] == 'a' || a[i] == 'A')
            count_a++;
    for (int64_t i = 0; i < static_cast<int64_t>(b.size()); ++i)
        if (b[i] == 'a' || b[i] == 'A')
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


int main() {
    std::vector<std::string> mass_original;
    mass_original.push_back(std::string("Class"));
    mass_original.push_back(std::string("Testus"));
    mass_original.push_back(std::string("hello_world"));
    mass_original.push_back(std::string("88005553535"));
    mass_original.push_back(std::string("jija"));
    bubbleSort(mass_original, comp_f);
    print_vct(mass_original);
    bubbleSort(mass_original, comp_s);
    print_vct(mass_original);
    bubbleSort(mass_original, comp_th);
    print_vct(mass_original);
    bubbleSort(mass_original, comp_fo);
    print_vct(mass_original);
    bubbleSort(mass_original, comp_fi);
    print_vct(mass_original);
    bubbleSortT(mass_original, [](std::string a, std::string b) {
        return a > b;
    });
    print_vct(mass_original);
    return 0;
}
