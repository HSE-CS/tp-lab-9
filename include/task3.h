// Copyright 2021 me
#ifndef INCLUDE_TASK3_H_
#define INCLUDE_TASK3_H_

#include <vector>
#include<queue>
#include <thread>

class Customer {
 private:
  size_t shop_list;

 public:
  Customer(size_t shop_list_ = 0) : shop_list(shop_list_) {}
  size_t get_shop_list() { return shop_list; }
};

class Shop {
 private:
  size_t max_customers;
  size_t max_product_list;
  size_t time_to_buy_product;
  size_t max_queue_len;
  size_t max_customer_delay;
  size_t surved_customers;
  std::vector<std::queue<Customer*>*> queues;
  std::vector<std::thread*> thread_list;
 public:
  Shop(size_t max_customers_ = 50, size_t max_product_list_ = 20,
       size_t time_to_buy_product_ = 100, size_t max_queue_len_ = 5,
       size_t max_customer_delay_ = 2000)
      : max_customers(max_customers_),
        max_product_list(max_product_list_),
        time_to_buy_product(time_to_buy_product_),
        max_queue_len(max_queue_len_),
        max_customer_delay(max_customer_delay_),
        surved_customers(0) {}
  void shopping();
  void surve_queue(std::queue<Customer*>* to_serve, size_t count);
};

#endif  // !INCLUDE_TASK3_H_
