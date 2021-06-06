// Copyright 2021 Egor Buzanov
#ifndef INCLUDE_TASK3_H_
#define INCLUDE_TASK3_H_

#include <chrono>
#include <queue>
#include <random>
#include <thread>
#include <vector>

class Client {
 public:
  std::vector<unsigned int> products;
  explicit Client();
};

void simulation(std::queue<Client *> *_queue);

class Supermarket {
 private:
  std::vector<std::thread *> threads;
  std::vector<std::queue<Client *>> clients;

 public:
  explicit Supermarket() = default;
  void createClients();
  void run();
};

#endif  // INCLUDE_TASK3_H_
