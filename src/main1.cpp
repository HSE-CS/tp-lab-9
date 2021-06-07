// Copyright Slavokeru 2021
#include"task1.h"

int main() {
  std::vector<std::string> Vec
  { "first", "second", "three", "four", "million", "monday" };
  BS(&Vec, [](std::string a, std::string b) {return a < b; });
  for_each(Vec.begin(), Vec.end(), [](std::string ob)
    {std::cout << ob << ' '; });
  std::cout << std::endl;
  BS(&Vec, [](std::string a, std::string b)
    {return a.size() < b.size(); });
  for_each(Vec.begin(), Vec.end(), [](std::string ob)
    {std::cout << ob << ' '; });
  std::cout << std::endl;
  BS(&Vec, [](std::string a, std::string b) {  return a[0] < b[0];});
  for_each(Vec.begin(), Vec.end(), [](std::string ob)
    {std::cout << ob << ' '; });
  std::cout << std::endl;
  BS(&Vec, [](std::string a, std::string b) {
  int ca{ 0 }, cb{ 0 };
  for_each(a.begin(), a.end(), [&ca](char ob)
    {ca += ob >= 'a' && ob <= 'z'; });
  for_each(b.begin(), b.end(), [&cb](char ob)
    {cb += ob >= 'a' && ob <= 'z'; });
  return ca < cb;
  });
  for_each(Vec.begin(), Vec.end(), [](std::string ob)
    {std::cout << ob << ' '; });
  std::cout << std::endl;
  BS(&Vec, [](std::string a, std::string b) {return a[1] < b[1]; });
  for_each(Vec.begin(), Vec.end(), [](std::string ob)
    {std::cout << ob << ' '; });
  return 0;
}
