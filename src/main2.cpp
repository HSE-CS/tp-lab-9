// Copyright Slavokeru 2021
#include"task2.h"

int main() {
  std::vector<std::string> Vec = { "a", "c", "d", "f", "e" };
  auto const comp = [](std::string a, std::string b) {return a < b; };
  bool srt{ false };
  std::mutex m;
  std::condition_variable c;
  std::thread sort([&]() mutable { BS(&Vec, comp, &srt, &m, &c); });
  while (!srt) {
    std::unique_lock<std::mutex> ul(m);
    c.wait(ul);
    for_each(Vec.begin(), Vec.end(), [](auto e) {std::cout << e << ' '; });
    std::cout << std::endl;
    ul.unlock();
  }
  sort.join();
  return 0;
}

