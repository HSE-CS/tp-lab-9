// Copyright 2021 SoDa

#include "task1.h"
#include <fstream>
#include <iostream>


void print_vct(std::vector<std::string> vect) {
    for (auto word : vect) {
        std::cout << word << ' ';
    }
    std::cout << std::endl;
}
