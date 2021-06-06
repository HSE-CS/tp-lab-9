// Copyright 2021 LongaBonga
#include "task1.h"
#include <algorithm>

int main() {
  std::vector<std::string> Strings = {"Blackjack", "girls", "Futurama", "yes", "I", "am", "Bender",
  "I", "mix", "alcohol", "my", "body", "is", "like", "a", "blender"};


  bubbleSort(Strings, [](std::string x, std::string y) {
             return x[0] < y[0]; });
  print(Strings);
  bubbleSort(Strings, [](std::string x, std::string y) {
             return x.back() < y.back(); });
  print(Strings);
  bubbleSort(Strings, [](std::string x, std::string y) {
             return x[x.size() / 3] < y[y.size() / 3]; });
  print(Strings);
  bubbleSort(Strings, [](std::string x, std::string y) {
             return x.size() < y.size(); });
  print(Strings);
  bubbleSort(Strings, [](std::string x, std::string y) {
    std::reverse(x.begin(), x.end());
    return x < y;
  });
  print(Strings);
  bubbleSort(Strings, [](std::string x, std::string y) {
    std::remove(x.begin(), x.end(), x[0]);
    std::remove(y.begin(), y.end(), y[0]);
    return x < y;
  });
  print(Strings);

  bubbleSort(Strings, [](std::string x, std::string y) { return x < y; });
  print(Strings);

  return 0;
}
