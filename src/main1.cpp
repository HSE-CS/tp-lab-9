// Copyright 10.06.21 DenisKabanov

#include "task1.h"

int main() {
  std::vector<std::string> arr = {"3", "2", "1", "15", "5", "0"};
  bubble(arr, [](std::string& s1, std::string& s2) {
      return std::stoi(s1) < std::stoi(s2);
      });
  print(arr);

  bubble(arr, [](std::string& s1, std::string& s2) {
      return std::stoi(s2) <  std::stoi(s1);
  });
  print(arr);

  bubble(arr, [](std::string& s1, std::string& s2) {
      return s1.size() < s2.size();
  });
  print(arr);

  bubble(arr, [](std::string& s1, std::string& s2) {
      return s2.size() < s1.size();
  });
  print(arr);

  bubble(arr, [](std::string& s1, std::string& s2) {
      return s1[0] < s2[0]; });
  print(arr);
  return 0;
}
