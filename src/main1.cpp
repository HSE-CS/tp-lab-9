// Copyright 2021 Kuznetsov Mikhail
#include "task1.h"
#include <algorithm>

int main() {
  std::vector<std::string> vectStr = {"summer", "is", "coming",
  "my", "dear", "friends"};
  bubbleSort(vectStr, [](std::string &x, std::string &y) { return x < y; });
  print(vectStr);
  bubbleSort(vectStr, [](std::string &x, std::string &y) {
             return x[0] < y[0]; });
  print(vectStr);
  bubbleSort(vectStr, [](std::string &x, std::string &y) {
             return x.back() < y.back(); });
  print(vectStr);
  bubbleSort(vectStr, [](std::string &x, std::string &y) {
             return x[x.size() / 2] < y[y.size() / 2]; });
  print(vectStr);
  bubbleSort(vectStr, [](std::string &x, std::string &y) {
             return x.size() < y.size(); });
  print(vectStr);
  bubbleSort(vectStr, [](std::string x, std::string y) {
    std::reverse(x.begin(), y.end());
    std::reverse(x.begin(), y.end());
    return x < y;
  });
  print(vectStr);
  bubbleSort(vectStr, [](std::string x, std::string y) {
    char a = x[0], b = y[0];
    std::remove(x.begin(), x.end(), a);
    std::remove(y.begin(), y.end(), b);
    return x < y;
  });
  print(vectStr);
  return 0;
}

