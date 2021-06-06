// Copyright 2021 LongaBonga
#include "task1.h"
#include <algorithm>

int main() {
  std::vector<std::string> Strings = {"Blackjack", "girls", "Futurama", "yes", "I", "am", "Bender",
  "I", "mix", "alcohol", "my", "body", "is", "like", "a", "blender"};


  std::function<bool(std::string, std::string)> comp1 = [](std::string x, std::string y) {
             return x[0] < y[0]; };
  bubbleSort(Strings, comp1);
  print(Strings);

  std::function<bool(std::string, std::string)> comp2 = [](std::string x, std::string y) {
             return x.back() < y.back(); };
  bubbleSort(Strings, comp2);
  print(Strings);

  std::function<bool(std::string, std::string)> comp3 =  [](std::string x, std::string y) {
             return x[x.size() / 3] < y[y.size() / 3]; };
  bubbleSort(Strings, comp3);
  print(Strings);

  std::function<bool(std::string, std::string)> comp4 = [](std::string x, std::string y) {
             return x.size() < y.size(); };
  bubbleSort(Strings, comp4);
  print(Strings);

  std::function<bool(std::string, std::string)> comp5 = [](std::string x, std::string y) {
    std::reverse(x.begin(), x.end());
    return x < y;
  };
  bubbleSort(Strings, comp5);
  print(Strings);

  std::function<bool(std::string, std::string)> comp6 = [](std::string x, std::string y) { return x < y; };
  bubbleSort(Strings, comp6);
  print(Strings);

  return 0;
}
