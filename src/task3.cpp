#include "task3.h"
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>
#include <vector>

const int MAX_CHECKOUTS = 5;
const int MAX_QUEUE_LENGTH = 5;
const int PRODUCT_INTERVAL_MS = 25;
const int CUSTOMER_INTERVAL_MS = 100;

struct Customer {
  std::vector<size_t> products;
  Customer() {
    int amount = (std::rand() % 25) + 1;
    for (int i = 0; i < amount; ++i) {
      products.push_back(std::rand());
    }
  }
};

struct CustomerQueue {
  std::queue<Customer> queue;
  std::mutex mutex;
  bool active = false;
};

void process_customer_queue(CustomerQueue &queue) {
  while (true) {
    queue.mutex.lock();
    Customer &customer = queue.queue.front();
    queue.mutex.unlock();
    for (auto p : customer.products) {
      std::this_thread::sleep_for(
          std::chrono::milliseconds(PRODUCT_INTERVAL_MS));
    }
    queue.mutex.lock();
    queue.queue.pop();
    if (queue.queue.empty()) {
      queue.active = false;
      queue.mutex.unlock();
      break;
    }
    queue.mutex.unlock();
  }
}

void start_model() {
  std::srand(10);
  CustomerQueue queues[MAX_CHECKOUTS];
  std::thread threads[MAX_CHECKOUTS];
  while (true) {
    Customer new_customer;
    bool done = false;
    std::cout << "---\n";
    for (int i = 0; i < MAX_CHECKOUTS; ++i) {
      auto &q = queues[i];
      q.mutex.lock();
      if (!done && q.queue.size() < MAX_QUEUE_LENGTH) {
        q.queue.push(new_customer);
        if (!q.active) {
          if (threads[i].joinable()) {
            threads[i].join();
          }
          threads[i] = std::thread(process_customer_queue, std::ref(q));
          q.active = true;
        }
        done = true;
      }
      std::cout << (q.active ? '*' : '.') << q.queue.size() << '\n';
      q.mutex.unlock();
    }
    std::this_thread::sleep_for(
        std::chrono::milliseconds(CUSTOMER_INTERVAL_MS));
  }
}
