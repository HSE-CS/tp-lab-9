// Copyright 2021 alexgiving

#include <iostream>
#include "task1.h"

int main() {
  std::vector<std::string> vector_elements = {"scapigerous", "distraint",
   "wheeled", "snobologist", "faultless", "heaps", "incitement", "windflaw" };
  std::cout << "Original sequence : ";
  print(vector_elements, ",");

  bubbleSort(vector_elements, [](std::string& s1, std::string& s2) {
    return s1 < s2; });
  print(vector_elements, ",");

  bubbleSort(vector_elements, [](std::string& s1, std::string& s2) {
    return s1.size() < s2.size(); });
  print(vector_elements, ",");

  bubbleSort(vector_elements, [](std::string& s1, std::string& s2) {
    return s1.back() < s2.back(); });
  print(vector_elements, ",");

  bubbleSort(vector_elements, [](std::string& s1, std::string& s2) {
    return s1[0] < s2[0]; });
  print(vector_elements, ",");

  bubbleSort(vector_elements, [](std::string& s1, std::string& s2) {
    char buffer1[s1.size()], buffer2[s2.size()];
    return s1.copy(buffer1, 1, s1.size()/2)
    < s2.copy(buffer2, 1, s2.size()/2); });
  print(vector_elements, ",");

  return 0;
}
