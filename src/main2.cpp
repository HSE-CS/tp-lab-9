// Copyright 2021 LongaBonga
#include <algorithm>

#include "task1.h"
#include "task2.h"

int main() {
  std::vector<std::string> Strings = {
      "Blackjack", "girls", "Futurama", "yes",     "I",  "am",
      "Bender",    "I",     "mix",      "alcohol", "my", "body",
      "is",        "like",  "a",        "blender"};

  std::function<bool(std::string, std::string)> comp1 =
      [](std::string x, std::string y) { return x[0] < y[0]; };
  bubbleSortParallel(Strings, comp1);
}
