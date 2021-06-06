// Copyright 2021 me

#include <iostream>
#include "../include/task3.h"

void Shop::shopping() {
  size_t customer_counter = 0;
  while (customer_counter < max_customers) {
    std::this_thread::sleep_for(
        std::chrono::milliseconds(std::rand() % max_customer_delay));
    bool in_queue = false;
    for (auto i = queues.begin(); i < queues.end(); ++i) {
      if ((*i)->size() < max_queue_len) {
        in_queue = true;
        (*i)->push(new Customer(std::rand() % max_product_list + 1));
        ++customer_counter;
        break;
      }
    }
    if (!in_queue) {
      std::queue<Customer *> *new_queue = new std::queue<Customer *>;
      new_queue->push(new Customer(std::rand() % max_product_list));
      queues.push_back(new_queue);
      thread_list.push_back(new std::thread(&Shop::surve_queue, this, new_queue, queues.size()));
    }
  }
  while (surved_customers < max_customers) {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
  }
  for (auto i : thread_list) {
    i->detach();
  }
}

void Shop::surve_queue(std::queue<Customer *> *to_serve, size_t count) {
  while (true) {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    while (!to_serve->empty()) {
      std::this_thread::sleep_for(std::chrono::milliseconds(
          to_serve->front()->get_shop_list() * time_to_buy_product));
      std::cout << "Queue number: " << count
                << " product list: " << to_serve->front()->get_shop_list()
                << " queue size: " << to_serve->size() << "\n";
      to_serve->pop();
      ++surved_customers;
    }
  }
}
