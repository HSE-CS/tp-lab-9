// Copyright NikDemoShow 2021
#include"task2.h"

int main() {
  std::vector<std::string> Sobj = { "gc", "gb", "af", "e", "ab" };
  auto const comp = [](std::string a, std::string b) {return a < b; };
  bool done{ false };
  std::mutex mu;
  std::condition_variable cv;
  std::thread sort([&]() mutable { Bsort(Sobj, comp, done, mu, cv); });
  while (!done) {
    std::unique_lock<std::mutex> ul(mu);
    cv.wait(ul);
    for_each(Sobj.begin(), Sobj.end(), [](auto el) {std::cout << el << ' '; });
    std::cout << std::endl;
    ul.unlock();
  }
  sort.join();
  return 0;
}

