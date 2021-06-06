// Copyright 2021 DB

#include "task2.h"

int main() {
  std::vector<std::string> vec = {"hell",  "be",   "english", "proffesional",
                                  "you", "proper", "window"};
  BSort(vec, [](std::string s1, std::string s2) {
    return s1.length() > s2.length();
  });
}
