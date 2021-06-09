//  Copyright 2021 GHA created by Klykov Anton

#include "task2.h"

extern std::mutex mu;
extern std::condition_variable cv;
extern bool finished;
extern bool sorted;
extern bool printed;

int main() {
  std::vector<std::string> strings{"hello", "world",
                                   "it", "my", "best",
                                   "summer"};
  std::thread th(bubble_sort, std::ref(strings),
                 [](std::string a, std::string  b)
                 {return a > b;});
  while (true) {
    std::unique_lock<std::mutex> uq(mu);
    cv.wait(uq, []() {return finished;});
    for (const auto& i : strings) {
      std::cout << i << " ";
    }
    std::cout << "\n";
    if (sorted) {
      break;
    }
    finished = false;
    printed = true;
    uq.unlock();
    cv.notify_all();
  }
  th.join();
  return 0;
}

