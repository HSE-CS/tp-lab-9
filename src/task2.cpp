#include "task2.h"
#include <chrono>
#include <condition_variable>
#include <functional>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

struct SortableStringVector {
  std::mutex mutex;
  std::vector<std::string> strings;
  int active_string = 0;
  std::condition_variable iteration_done;
  bool new_data_to_print = false;
  bool is_done = false;
  std::function<bool(const std::string &, const std::string &)> gt_comp;

  SortableStringVector() {
    auto string_f = []() {
      std::string s;
      int max_chars = std::rand() % 25;
      for (int i = 0; i < max_chars; ++i) {
        s.push_back((std::rand() % ('a' - 'A')) + 'A');
      }
      return s;
    };
    gt_comp = [](const std::string &a, const std::string &b) {
      return a.length() > b.length();
    };

    for (int i = 0; i < 25; ++i) {
      strings.push_back(string_f());
    }
  }

  void print() {
    int i = 0;
    for (const auto &s : strings) {
      if (i == active_string) {
        std::cout << '*';
      } else {
        std::cout << ' ';
      }
      std::cout << s.length() << "\t| " << s << '\n';
      i += 1;
    }
    std::cout << std::endl;
  }
};

void bubble_sort(SortableStringVector &ssv) {
  auto it_begin = ssv.strings.begin();
  auto it_end = ssv.strings.end();
  for (size_t i = it_end - it_begin - 1; i > 0; --i) {
    for (size_t j = 0; j < i; ++j) {
      auto a = it_begin + j;
      auto b = it_begin + j + 1;
      ssv.mutex.lock();
      ssv.active_string = j + 1;
      if (ssv.gt_comp(*a, *b)) {
        std::iter_swap(a, b);
      }
      ssv.new_data_to_print = true;
      ssv.mutex.unlock();
      ssv.iteration_done.notify_one();
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
  }
  ssv.mutex.lock();
  ssv.is_done = true;
  ssv.mutex.unlock();
  ssv.iteration_done.notify_one();
}

void parallel_sort() {
  SortableStringVector ssv;

  auto t1 = std::thread(bubble_sort, std::ref(ssv));

  while (true) {
    std::unique_lock<std::mutex> lk(ssv.mutex);
    ssv.iteration_done.wait(
        lk, [&]() { return ssv.new_data_to_print || ssv.is_done; });
    if (ssv.new_data_to_print) {
      ssv.print();
      ssv.new_data_to_print = false;
    }
    if (ssv.is_done) {
      break;
    }
  }

  t1.join();
}
