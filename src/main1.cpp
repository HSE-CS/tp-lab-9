// Copyright 2021 FOM

#include "task1.h"
//
//template <typename Te>
//void print_sorted(std::function<Te(void)> initial_data_,
// std::function<bool(const Te &, const Te &)> comp) {
//  std::vector<Te> initial_data = {};
//  for (int i = 0; i < 10; i++) {
//    initial_data.push_back(initial_data_());
//  }
//  BubbleSort(initial_data.begin(), initial_data.end(), comp);
//  for (auto i : initial_data) {
//      std::cout << i << ' ';
//  }
//  std::cout<< std::endl;
//  std::cout<< std::endl;
//}
//
//template <typename Te>
//void print_sorted_test(std::vector<Te> initial_data,
// std::function<bool(const Te&, const Te&)> comp) {
//    std::vector<Te> answer = {};
//    BubbleSort(initial_data.begin(), initial_data.end(), comp);
//    for (auto i : initial_data) {
//        std::cout << i << ' ';
//    }
//    std::cout << std::endl;
//    std::cout << std::endl;
//}
//
//int main() {
//    std::cout << "function_1" << std::endl;
//    std::function<std::string(void)> example_string = []() {
//        std::string str;
//        int max_ = std::rand() % 25;
//        for (int i = 0; i < max_; i++) {
//            str.push_back((std::rand() % ('a' - 'A')) + 'A');
//        }
//        return str;
//    };
//    std::function<bool(const std::string&,
//        const std::string&)> example_string_comp =
//        [](const std::string& x, const std::string& y) { return x > y; };
//    print_sorted(example_string, example_string_comp);
//
//    std::cout << "function_2" << std::endl;
//    std::function<int(void)> example_int = []() {
//        return std::rand() % 50;
//    };
//    std::function<bool(const int&, const int&) > example_int_comp =
//        [](const int& x, const int& y) {
//        return x > y;
//    };
//    print_sorted(example_int, example_int_comp);
//
//    std::cout << "function_3" << std::endl;
//    std::function<double(void)> example_float = []() {
//        return static_cast<double>(std::rand() % 10) / (std::rand() % 50);
//    };
//    std::function<bool(const double&, const double&)> example_float_comp =
//        [](const double& x, const double& y) { return x > y; };
//    print_sorted(example_float, example_float_comp);
//
//    std::cout << "function_4" << std::endl;
//    std::function<bool(const int&, const int&)> example_int_com =
//        [](const int& x, const int& y) { return x < y; };
//    print_sorted(example_int, example_int_com);
//
//
//    std::cout << "function_5" << std::endl;
//    std::function<bool(void)> example_bool = []() { return std::rand() % 2; };
//    std::function<bool(const bool&, const bool&)> example_bool_comp =
//        [](const bool& x, const bool& y) { return x > y; };
//    print_sorted(example_bool, example_bool_comp);
//
//    std::cout << "test_1" << std::endl;
//    std::vector<bool> test_1 = { 1, 1, 1, 1, 1, 0, 0, 0, 0, 0 };
//    std::vector<bool> answ = {};
//    std::function<bool(const bool&, const bool&)> example_bool_test =
//        [](const bool& x, const bool& y) { return x > y; };
//    print_sorted_test(test_1, example_bool_test);
//
//    std::cout << "test_2" << std::endl;
//    std::vector<std::string> str = { "m", "o", "n", "d", "a", "y" };
//    std::function<bool(const std::string&, const std::string&)> example_string_comp_test =
//        [](const std::string& x, const std::string& y) { return x > y; };
//    print_sorted_test(str, example_string_comp_test);
//
//    return 0;
//}
