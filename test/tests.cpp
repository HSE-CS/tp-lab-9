// Copyright 2021 Kuznetsov Mikhail
#include <gtest/gtest.h>
#include "task1.h"
#include "task2.h"
#include "task3.h"
#include <algorithm>
#include <thread>
#include <mutex>
#include <condition_variable>

extern bool isPrinted;
extern bool isSorted;
extern bool isStepped;
extern std::mutex myMutex;
extern std::condition_variable condVar;

TEST(Task1, test1) {
  std::vector<std::string> vectStr = {"summer", "is", "coming",
  "my", "dear", "friends"};
  bubbleSort(vectStr, [](std::string &x, std::string &y) { return x < y; });
  std::vector<std::string> expect =
  {"coming", "dear", "friends", "is", "my", "summer"};
  EXPECT_EQ(expect, vectStr);
}

TEST(Task1, test2) {
  std::vector<std::string> vectStr = {"Summer", "is", "coming",
  "my", "Dear", "Friends"};
  bubbleSort(vectStr, [](std::string &x, std::string &y) { return x < y; });
  std::vector<std::string> expect =
  {"Dear", "Friends", "Summer", "coming", "is", "my"};
  EXPECT_EQ(expect, vectStr);
}

TEST(Task1, test3) {
  std::vector<std::string> vectStr = {"summer", "is", "coming",
  "my", "dear", "friends"};
  bubbleSort(vectStr, [](std::string &x, std::string &y) {
             return x.back() < y.back(); });
  std::vector<std::string> expect =
  {"coming", "dear", "summer", "friends", "is", "my"};
  EXPECT_EQ(expect, vectStr);
}

TEST(Task1, test4) {
  std::vector<std::string> vectStr = {"summer", "is", "coming",
  "my", "dear", "friends"};
  bubbleSort(vectStr, [](std::string &x, std::string &y) {
             return x[x.size() / 2] < y[y.size() / 2]; });
  std::vector<std::string> expect =
  {"dear", "friends", "coming", "summer", "is", "my"};
  EXPECT_EQ(expect, vectStr);
}

TEST(Task1, test5) {
  std::vector<std::string> vectStr = {"summer", "is", "coming",
  "my", "dear", "friends"};
  bubbleSort(vectStr, [](std::string &x, std::string &y) {
             return x.size() < y.size(); });
  std::vector<std::string> expect =
  {"is", "my", "dear", "coming", "summer", "friends"};
  EXPECT_EQ(expect, vectStr);
}

TEST(Task1, test6) {
  std::vector<std::string> vectStr = {"summer", "is", "coming",
  "my", "dear", "friends"};
  bubbleSort(vectStr, [](std::string x, std::string y) {
    std::reverse(x.begin(), y.end());
    std::reverse(x.begin(), y.end());
    return x < y;
  });
  std::vector<std::string> expect =
  {"coming", "dear", "friends", "is", "my", "summer"};
  EXPECT_EQ(expect, vectStr);
}

TEST(Task1, test7) {
  std::vector<std::string> vectStr = {"summer", "is", "coming",
  "my", "dear", "friends"};
  bubbleSort(vectStr, [](std::string x, std::string y) {
    char a = x[0], b = y[0];
    std::remove(x.begin(), x.end(), a);
    std::remove(y.begin(), y.end(), b);
    return x < y;
  });
  std::vector<std::string> expect =
  {"dear", "coming", "friends", "is", "summer", "my"};
  EXPECT_EQ(expect, vectStr);
}

TEST(Task2, test1) {
  std::vector<std::string> vectStr = {"summer", "is", "coming"};
  auto comp = [](const std::string &x, const std::string &y)
  -> bool { return x < y; };
  std::thread myThread(simpleBubbleSort, std::ref(vectStr), comp);
  std::vector<std::vector<std::string>> printed;
  while (!isSorted) {
    std::unique_lock<std::mutex> unqLock(myMutex);
    condVar.wait(unqLock, [](){ return isStepped; });
    printed.push_back(vectStr);
    isStepped = false;
    isPrinted = true;
    unqLock.unlock();
    condVar.notify_all();
  }
  myThread.join();
  isPrinted = true;
  isStepped = false;
  isSorted = false;
  std::vector<std::vector<std::string>> expect =
  {{"is", "summer", "coming"}, {"is", "coming", "summer"},
            {"coming", "is", "summer"}, {"coming", "is", "summer"},
  {"coming", "is", "summer"}, {"coming", "is", "summer"}};
  EXPECT_EQ(expect, printed);
}

TEST(Task2, test2) {
  std::vector<std::string> vectStr = {"summer", "is", "coming"};
  auto comp = [](const std::string &x, const std::string &y)
  -> bool { return x.back() < y.back(); };
  std::thread myThread(simpleBubbleSort, std::ref(vectStr), comp);
  std::vector<std::vector<std::string>> printed;
  while (!isSorted) {
    std::unique_lock<std::mutex> unqLock(myMutex);
    condVar.wait(unqLock, [](){ return isStepped; });
    printed.push_back(vectStr);
    isStepped = false;
    isPrinted = true;
    unqLock.unlock();
    condVar.notify_all();
  }
  myThread.join();
  isPrinted = true;
  isStepped = false;
  isSorted = false;
  std::vector<std::vector<std::string>> expect =
  {{"summer", "is", "coming"}, {"summer", "coming", "is"},
            {"coming", "summer", "is"}, {"coming", "summer", "is"},
  {"coming", "summer", "is"}, {"coming", "summer", "is"}}
  EXPECT_EQ(expect, printed);
}

TEST(Task2, test3) {
  std::vector<std::string> vectStr = {"summer", "is", "coming"};
  auto comp = [](const std::string &x, const std::string &y)
  -> bool { return x.size() < y.size(); };
  std::thread myThread(simpleBubbleSort, std::ref(vectStr), comp);
  std::vector<std::vector<std::string>> printed;
  while (!isSorted) {
    std::unique_lock<std::mutex> unqLock(myMutex);
    condVar.wait(unqLock, [](){ return isStepped; });
    printed.push_back(vectStr);
    isStepped = false;
    isPrinted = true;
    unqLock.unlock();
    condVar.notify_all();
  }
  myThread.join();
  isPrinted = true;
  isStepped = false;
  isSorted = false;
  std::vector<std::vector<std::string>> expect =
  {{"is", "summer", "coming"}, {"is", "summer", "coming"},
            {"is", "summer", "coming"}, {"is", "summer", "coming"},
  {"is", "summer", "coming"}, {"is", "summer", "coming"}}
  EXPECT_EQ(expect, printed);
}

TEST(Task2, test4) {
  std::vector<std::string> vectStr = {"summer", "is", "coming"};
  auto comp = [](const std::string &x, const std::string &y)
  -> bool { return x[x.size() / 2] < y[y.size() / 2]; };
  std::thread myThread(simpleBubbleSort, std::ref(vectStr), comp);
  std::vector<std::vector<std::string>> printed;
  while (!isSorted) {
    std::unique_lock<std::mutex> unqLock(myMutex);
    condVar.wait(unqLock, [](){ return isStepped; });
    printed.push_back(vectStr);
    isStepped = false;
    isPrinted = true;
    unqLock.unlock();
    condVar.notify_all();
  }
  myThread.join();
  isPrinted = true;
  isStepped = false;
  isSorted = false;
  std::vector<std::vector<std::string>> expect =
  {{"summer", "is", "coming"}, {"summer", "coming", "is"},
            {"coming", "summer", "is"}, {"coming", "summer", "is"},
  {"coming", "summer", "is"}, {"coming", "summer", "is"}}
  EXPECT_EQ(expect, printed);
}

TEST(Task2, test5) {
  std::vector<std::string> vectStr = {"summer", "is", "coming"};
  auto comp = [](const std::string &x, const std::string &y)
  -> bool { return x[0] + x.back() < y[0] + y.back(); };
  std::thread myThread(simpleBubbleSort, std::ref(vectStr), comp);
  std::vector<std::vector<std::string>> printed;
  while (!isSorted) {
    std::unique_lock<std::mutex> unqLock(myMutex);
    condVar.wait(unqLock, [](){ return isStepped; });
    printed.push_back(vectStr);
    isStepped = false;
    isPrinted = true;
    unqLock.unlock();
    condVar.notify_all();
  }
  myThread.join();
  isPrinted = true;
  isStepped = false;
  isSorted = false;
  std::vector<std::vector<std::string>> expect =
  {{"is", "summer", "coming"}, {"is", "coming", "summer"},
            {"coming", "is", "summer"}, {"coming", "is", "summer"},
  {"coming", "is", "summer"}, {"coming", "is", "summer"}}
  EXPECT_EQ(expect, printed);
}

TEST(Task3, test1) {
  std::vector <int> check = {10, 8, 15};
  Buyer* buyer = new Buyer(check);
  EXPECT_EQ(check, buyer->check);
}

TEST(Task3, test2) {
  Buyer* buyer1 = new Buyer({10, 8, 14});
  Buyer* buyer2 = new Buyer({5, 12, 2});
  Buyer* buyer3 = new Buyer({4, 3, 6});
  std::queue <Buyer*> *q = new std::queue<Buyer*>;
  q->push(buyer1);
  q->push(buyer2);
  q->push(buyer3);
  Supermarket* supermarket = new Supermarket(15, 40, 10, 5);
  supermarket->serveQueue(q);
  EXPECT_EQ(0, q->size());
}

TEST(Task3, test3) {
  Buyer* buyer1 = new Buyer({9, 8});
  Buyer* buyer2 = new Buyer({5, 6, 7, 8});
  Buyer* buyer3 = new Buyer({2, 4, 1, 3});
  Buyer* buyer4 = new Buyer({8});
  std::queue <Buyer*> *q = new std::queue<Buyer*>;
  q->push(buyer1);
  q->push(buyer2);
  q->push(buyer3);
  q->push(buyer4);
  Supermarket* supermarket = new Supermarket(15, 40, 10, 5);
  supermarket->serveQueue(q);
  EXPECT_EQ(0, q->size());
}

TEST(Task3, test4) {
  Buyer* buyer1 = new Buyer({7, 8, 9, 10});
  Buyer* buyer2 = new Buyer({5, 4});
  Buyer* buyer3 = new Buyer({2, 8, 13});
  std::queue <Buyer*> *q = new std::queue<Buyer*>;
  q->push(buyer1);
  q->push(buyer2);
  q->push(buyer3);
  Supermarket* supermarket = new Supermarket(15, 40, 10, 5);
  supermarket->serveQueue(q);
  EXPECT_EQ(0, q->size());
}

TEST(Task3, test5) {
  Buyer* buyer1 = new Buyer({2, 3, 1, 4, 5});
  Buyer* buyer2 = new Buyer({2, 4});
  std::queue <Buyer*> *q = new std::queue<Buyer*>;
  q->push(buyer1);
  q->push(buyer2);
  Supermarket* supermarket = new Supermarket(15, 40, 10, 5);
  supermarket->serveQueue(q);
  EXPECT_EQ(0, q->size());
}
