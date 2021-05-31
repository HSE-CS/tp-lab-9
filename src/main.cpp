// Copyright 2021 SoDa

#include "task1.h"
#include <iostream>

int main() {
	std::vector<std::string> mass_original;
	mass_original.push_back(std::string("Aboba"));
	mass_original.push_back(std::string("SeRg"));
	mass_original.push_back(std::string("hello_world"));
	mass_original.push_back(std::string("Final"));
	mass_original.push_back(std::string("GoD_JoB"));
	mass_original.push_back(std::string("12"));
	mass_original.push_back(std::string("tb-lab-9"));
	buble_sort(mass_original, comp_1);
	for (auto word : mass_original) {
		std::cout << word << std::endl;
	}
	return 0;
}
