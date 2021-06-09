//  Copyright 2021 GHA created by Klykov Anton

#ifndef INCLUDE_TASK3_H_
#define INCLUDE_TASK3_H_

#include <iostream>
#include <vector>
#include <queue>
#include <mutex>
#include <random>
#include <thread>

class Customer {
 public:
  std::vector<int> _perches_costumer;
  explicit Customer(std::vector<int>& perches_costumer);
};

class Shop {
 private:
  std::vector<std::thread*> threads;
  int _number_customers;
  int _queue_length;
  std::mutex _mutex;

 public:
  explicit Shop(int number_customer, int queue_length);
  void _serve_queue(std::queue<Customer*>* serving_queue);
  void _serve_customer(Customer* customer, int position);
  void _start_serve_customers();
  void open_shop();
  Customer* _customer();
};

#endif  // INCLUDE_TASK3_H_
