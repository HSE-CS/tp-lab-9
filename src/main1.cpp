#include <cstdlib>
#include <functional>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

#include "task1.h"

template <typename T>
void sort_test(std::function<T(void)> gen_f,
               std::function<bool(const T &, const T &)> gt_comp) {
  std::vector<T> v = {};
  for (int i = 0; i < 20; ++i) {
    v.push_back(gen_f());
  }
  std::cout << "Unsorted: ";
  for (auto v : v) {
    std::cout << v << ' ';
  }
  std::cout << '\n';
  bubble_sort(v.begin(), v.end(), gt_comp);
  std::cout << "Sorted: ";
  for (auto v : v) {
    std::cout << v << ' ';
  }
  std::cout << '\n' << std::endl;
}

int main() {
  std::srand(1);

  std::function<int(void)> int_f = []() { return std::rand() % 100; };
  std::function<bool(const int &, const int &)> int_gt_comp =
      [](const int &a, const int &b) { return a > b; };
  sort_test(int_f, int_gt_comp);

  std::function<double(void)> double_f = []() {
    return static_cast<double>(std::rand() % 100) / (std::rand() % 100);
  };
  std::function<bool(const double &, const double &)> double_comp =
      [](const double &a, const double &b) { return a > b; };
  sort_test(double_f, double_comp);

  std::function<bool(const int &, const int &)> int_lt_comp =
      [](const int &a, const int &b) { return a < b; };
  sort_test(int_f, int_lt_comp);

  std::function<bool(void)> bool_f = []() { return std::rand() % 2; };
  std::function<bool(const bool &, const bool &)> bool_gt_comp =
      [](const bool &a, const bool &b) { return a > b; };
  sort_test(bool_f, bool_gt_comp);

  std::function<std::string(void)> string_f = []() {
    std::string s;
    int max_chars = std::rand() % 25;
    for (int i = 0; i < max_chars; ++i) {
      s.push_back((std::rand() % ('a' - 'A')) + 'A');
    }
    return s;
  };
  std::function<bool(const std::string &, const std::string &)> string_gt_comp =
      [](const std::string &a, const std::string &b) { return a > b; };
  sort_test(string_f, string_gt_comp);
}
