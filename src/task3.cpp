// Copyright 2021 Egor Buzanov

#include "../include/task3.h"

Client::Client() {
  std::random_device rd;
  std::mt19937 mersenne(rd());
  unsigned int size = mersenne() % 10 + 1;
  for (size_t i = 0; i < size; i++) {
    products.push_back(mersenne() % 100);
  }
}

void Supermarket::createClients() {
  std::random_device rd;
  std::mt19937 mersenne(rd());
  unsigned int queue_num = mersenne() % 3 + 1;
  for (size_t i = 0; i < queue_num; i++) {
    unsigned int clients_num = mersenne() % 5 + 1;
    std::queue<Client *> new_queue;
    for (size_t j = 0; j < clients_num; j++) {
      new_queue.push(new Client());
    }
    clients.push_back(new_queue);
  }
}

void simulation(std::queue<Client *> *_queue) {
  while (!(_queue->empty())) {
    for (auto product : _queue->front()->products) {
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    _queue->pop();
  }
}

void Supermarket::run() {
  createClients();
  for (unsigned int i = 0; i < clients.size(); i++) {
    threads.push_back(new std::thread(simulation, &(clients[i])));
  }
  std::random_device rd;
  std::mt19937 mersenne(rd());
  for (size_t i = 0; i < mersenne() % 100; i++) {
    if (mersenne() % 2 == 0) {
      clients[mersenne() % clients.size()].push(new Client());
    }
  }
  for (auto thread : threads) {
    thread->join();
  }
}
