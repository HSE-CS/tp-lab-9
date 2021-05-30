// Copyright 2021 Kuznetsov Mikhail
#include "task2.h"
#include <thread>
#include <mutex>
#include <condition_variable>

extern bool isPrinted;
extern bool isSorted;
extern bool isStepped;
extern std::mutex myMutex;
extern std::condition_variable condVar;

int main() {
  std::vector<std::string> vectStr = {"summer", "is", "coming",
  "my", "dear", "friends"};
  auto comp = [](const std::string &x, const std::string &y)
  -> bool { return x < y; };
  std::thread myThread(simpleBubbleSort, std::ref(vectStr), comp);
  while(!isSorted) {
    std::unique_lock<std::mutex> unqLock(myMutex);
    condVar.wait(unqLock, [](){ return isStepped; });
    printVectStr(vectStr);
    isStepped = false;
    isPrinted = true;
    unqLock.unlock();
    condVar.notify_all();
  }
  myThread.join();
  return 0;
}

