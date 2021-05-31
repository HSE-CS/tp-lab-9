// Copyright 2021 Kuznetsov Mikhail
#include "task2.h"
#include <thread>

bool isPrinted = true;
bool isSorted = false;
bool isStepped = false;
std::mutex myMutex;
std::condition_variable condVar;

void simpleBubbleSort(std::vector<std::string> &_arr,
                  bool _comp(const std::string &_x, const std::string &_y)) {
  std::size_t n = _arr.size();
  for (std::size_t i = 0; i < n; i++) {
    for (std::size_t j = 0; j < n - 1; j++) {
      std::unique_lock<std::mutex> unqLock(myMutex);
      condVar.wait(unqLock, [](){ return isPrinted; });
      if (_comp(_arr[j + 1], _arr[j])) {
        std::swap(_arr[j], _arr[j + 1]);
      }
      isStepped = true;
      isPrinted = false;
      unqLock.unlock();
      condVar.notify_all();
    }
  }
  isSorted = true;
}

void printVectStr(std::vector<std::string> &_arr) {
  for (auto x : _arr) {
    std::cout << x << ' ';
  }
  std::cout << '\n';
}

