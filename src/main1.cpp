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
	bubble_sort(mass_original, comp_1);
	print_vct(mass_original);
	bubble_sort(mass_original, comp_2);
	print_vct(mass_original);
	bubble_sort(mass_original, comp_3);
	print_vct(mass_original);
	bubble_sort(mass_original, comp_4);
	print_vct(mass_original);
	bubble_sort(mass_original, comp_5);
	print_vct(mass_original);
	BubbleSort_T(mass_original, [](std::string a, std::string b) {return a > b; });
	print_vct(mass_original);
	return 0;
}
