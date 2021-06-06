// Copyright 2021 SoDa

#include "task1.h"
#include <fstream>
#include <iostream>


void print_vct(const std::vector<const std::string>& vect) {
    for (auto word : vect) {
        std::cout << word << ' ';
    }
    std::cout << std::endl;
}
