// Copyright 2021 Bogomazov

#include "../include/task_first.h"

int main() {
    std::vector<std::string> mass_original;
    mass_original.push_back(std::string("Aboba"));
    mass_original.push_back(std::string("SeRg"));
    mass_original.push_back(std::string("hello_world"));
    mass_original.push_back(std::string("Final"));
    mass_original.push_back(std::string("GoD_JoB"));
    mass_original.push_back(std::string("12"));
    mass_original.push_back(std::string("tb-lab-9"));
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
