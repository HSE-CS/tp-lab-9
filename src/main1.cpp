// Copyright NikDemoShow 2021
#include"task1.h"

int main() {
  std::vector<std::string> Sobj { "UPAA", "Bcd&1%^qA", "uAAaa   a", "ub/+", "!;;'", "o" };
  Bsort(Sobj, [](std::string a, std::string b) {return a < b; });
  for_each(Sobj.begin(), Sobj.end(), [](std::string ob) {std::cout << ob << ' '; });
  std::cout << std::endl;
  Bsort(Sobj, [](std::string a, std::string b) {return a.size() < b.size(); });
  for_each(Sobj.begin(), Sobj.end(), [](std::string ob) {std::cout << ob << ' '; });
  std::cout << std::endl;
  Bsort(Sobj, [](std::string a, std::string b) {
    int ca{ 0 }, cb{ 0 };
    for_each(a.begin(), a.end(), [&ca](char ob) {ca += ob >= 'A' && ob <= 'Z'; });
    for_each(b.begin(), b.end(), [&cb](char ob) {cb += ob >= 'A' && ob <= 'Z'; });
    return ca < cb;
    });
  for_each(Sobj.begin(), Sobj.end(), [](std::string ob) {std::cout << ob << ' '; });
  std::cout << std::endl;
  Bsort(Sobj, [](std::string a, std::string b) {
  int ca{ 0 }, cb{ 0 };
  for_each(a.begin(), a.end(), [&ca](char ob) {ca += ob >= 'a' && ob <= 'z'; });
  for_each(b.begin(), b.end(), [&cb](char ob) {cb += ob >= 'a' && ob <= 'z'; });
  return ca < cb; 
  });
  for_each(Sobj.begin(), Sobj.end(), [](std::string ob) {std::cout << ob << ' '; });
  std::cout << std::endl;
  Bsort(Sobj, [](std::string a, std::string b) {int ca{ 0 }, cb{ 0 };
  for_each(a.begin(), a.end(), [&ca](char ob) {ca += ob < 'A' || ob > 'Z' && ob < 'a' || ob > 'z'; });
  for_each(b.begin(), b.end(), [&cb](char ob) {cb += ob < 'A' || ob > 'Z' && ob < 'a' || ob > 'z'; });
  return ca < cb; 
  });
  for_each(Sobj.begin(), Sobj.end(), [](std::string ob) {std::cout << ob << ' '; });
  return 0;
}
