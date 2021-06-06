// Copyright 2021 Egor Buzanov

#include "../include/task2.h"

std::mutex mx;
std::condition_variable cv;

bool finished = false;
bool sorted = false;

void threadBubbleSort(std::vector<std::string> *_array,
                      std::function<bool(std::string, std::string)> _comp) {
  for (size_t i = 0; i < _array->size() - 1; i++) {
    {
      std::lock_guard<std::mutex> lk(mx);
      for (size_t j = 0; j < _array->size() - i - 1; j++) {
        if (_comp((*_array)[j], (*_array)[j + 1])) {
          std::string tmp;
          tmp = (*_array)[j];
          (*_array)[j] = (*_array)[j + 1];
          (*_array)[j + 1] = tmp;
        }
      }
    }
    sorted = true;
    cv.notify_all();
  }
  {
    std::lock_guard<std::mutex> lk(mx);
    finished = true;
  }
  cv.notify_all();
}

void threadPrint(const std::vector<std::string> &_array) {
  while (true) {
    {
      std::unique_lock<std::mutex> lk(mx);
      cv.wait(lk, []() { return sorted; });
      for (const auto str : _array) {
        std::cout << str << std::endl;
      }
      std::cout << std::endl;
    }
    sorted = false;
    if (finished) {
      break;
    }
  }
}
