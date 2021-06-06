// Copyright 2021 alexgiving

#include "task2.h"

int main() {
  std::vector<std::string> arr = {"snobologist", "faultless",
                                  "heaps", "incitement"};
  bubbleSort(arr, [](const std::string& s1, const std::string& s2) {
    return s1.length() > s2.length(); });
}
