// Copyright 2021 valvarl

#include <iostream>
#include "task1.cpp"


int main() {
    int arr_int[] = {1, 6, 10, 64, 7, 5, 8, 1, 7, 15, 18, 20, 26};
    bubble_sort<int>(&arr_int, [](int a, int b) {return a > b;});

    for (int i{ 0 }; i < 13; i++) std::cout << arr_int[i] << ' ';
    std::cout << std::endl;

    double arr_double[] = {1.1, 3.4, 5, 7, 2, 7, 6.6, 4, 6.1, 10};
    bubble_sort<double>(&arr_double, [](double a, double b) {return a > b;});

    for (int i{ 0 }; i < 10; i++) std::cout << arr_double[i] << ' ';
    std::cout << std::endl;

    std::string arr_string[] = {"aa", "bbbb", "ccc", "ddddddd", "e", "ff"};
    bubble_sort<std::string>(&arr_string,
            [](const std::string& a, const std::string& b) {
        return a.length() > b.length();
    });

    for (int i{ 0 }; i < 6; i++) std::cout << arr_string[i] << ' ';
    std::cout << std::endl;

    std::string arr_string2[] = {"ff", "ccc","aa", "bbbb", "ddddddd", "e"};
    bubble_sort<std::string>(&arr_string2,
                             [](const std::string& a, const std::string& b) {
                                 return a > b;
                             });

    for (int i{ 0 }; i < 6; i++) std::cout << arr_string2[i] << ' ';
    std::cout << std::endl;

    std::string arr_string3[] = {"ff", "ccc","aa", "bbbb", "ddddddd", "e"};
    bubble_sort<std::string>(&arr_string3,
                             [](const std::string& a, const std::string& b) {
                                    if (a.length() > b.length()) {
                                        return true;
                                    } else if (a.length() == b.length()) {
                                        return a > b;
                                    } else {
                                        return false;
                                    }
                             });

    for (int i{ 0 }; i < 6; i++) std::cout << arr_string3[i] << ' ';
    std::cout << std::endl;

    return 0;
}
