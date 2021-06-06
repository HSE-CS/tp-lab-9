// Copyright 2021 me
#include<iostream>
#include<functional>
#include<string>
#include <vector>
#include<cmath>

#include "../include/task1.h"


std::function<bool(std::string, std::string)> f1 =
    [](std::string s1, std::string s2) { return s1.size() > s2.size(); };  // сортировка по размеру

std::function<bool(std::string, std::string)> f2 = [](std::string s1,
                                                     std::string s2) {
  int count = 0;
  for (auto i : s1) {
    if (i == ' ') ++count;
  }
  for (auto i : s2) {
    if (i == ' ') --count;
  }
  return count > 0;
};  // количеству пробелов

std::function<bool(std::string, std::string)> f3 = [](std::string s1, std::string s2) {
  int count = 0;
  for (auto i : s1) {
    if (i == 'a' || i == 'e' || i == 'y' || i == 'u' || i == 'i' || i == 'o' ||
        i == 'A' || i == 'E' || i == 'Y' || i == 'U' || i == 'I' || i == 'O')
      ++count;
  }
  for (auto i : s2) {
    if (i == 'a' || i == 'e' || i == 'y' || i == 'u' || i == 'i' || i == 'o' ||
        i == 'A' || i == 'E' || i == 'Y' || i == 'U' || i == 'I' || i == 'O')
      --count;
  }
  return count > 0;
};  // количеству глассных

std::function<bool(std::string, std::string)> f4 = [](std::string s1, std::string s2) {
  int count = 0;
  for (auto i : s1) {
    if (i >= 'A' && i <='Z')
      ++count;
  }
  for (auto i : s2) {
    if (i >= 'A' && i <= 'Z') --count;
  }
  return count > 0;
};  // количеству больших букв

std::function<bool(std::string, std::string)> f5 = [](std::string s1, std::string s2) {
  size_t size = (s1.size() > s2.size()? s1.size() : s2.size());
  for (size_t i = 0; i < size; ++i) {
    if (i == s1.size()) return false;
    if (i == s2.size()) return true;
    if (s1[i] > s2[i]) return true;
  }
  return false;
};


int main() {
  std::vector<std::string> v;
  v.push_back("Hello   ");
  v.push_back("WORLD");
  v.push_back("long string with a lot of spaces");
  v.push_back("TP laaab 9");

  bubble_sort(v, f1);
  print_vector(v);

  bubble_sort(v, f2);
  print_vector(v);

  bubble_sort(v, f3);
  print_vector(v);

  bubble_sort(v, f4);
  print_vector(v);

  bubble_sort(v, f5);
  print_vector(v);
}
