//  Copyright 2021 GHA created by Klykov Anton

#include "task3.h"

Customer::Customer(std::vector<int> &perches_costumer) {
  _perches_costumer = perches_costumer;
}

Shop::Shop(int number_customer, int queue_length) {
  _number_customers = number_customer;
  _queue_length = queue_length;
}

void Shop::open_shop() {
  this->_start_serve_customers();
  for (int i = 0; i < threads.size(); ++i) {
    threads[i]->join();
  }
}

Customer* Shop::_customer() {
  std::random_device _rd;
  std::mt19937 _random(_rd());
  std::vector<int> perches_costumer;
  int _amount_products =
      static_cast<int>((_random() % 10) + 1);
  for (size_t i = 0; i < _amount_products; ++i) {
    perches_costumer.push_back(
        static_cast<int>((_random() % 200) + 10));
  }
  return new Customer(perches_costumer);
}

void Shop::_serve_customer(Customer* customer, int position) {
  for (size_t i = 0; i < customer->_perches_costumer.size(); ++i) {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::unique_lock<std::mutex> ul(_mutex);
    std::cout << "Customer " << position << " in thread: "
    << std::this_thread::get_id() << " has products: "
    << customer->_perches_costumer[i] << "\n";
    ul.unlock();
  }
  std::cout << "\n";
}

void Shop::_serve_queue (std::queue<Customer*>*
    serving_queue) {
  int position = 1;
  while (!serving_queue->empty()) {
    auto* customer = serving_queue->front();
    serving_queue->pop();
    _serve_customer(customer, position);
    position++;
  }
  delete serving_queue;
}

void Shop::_start_serve_customers() {
  auto* queues_customers = new
      std::vector<std::queue<Customer*>*>;
  bool is_queue = false;
  for (size_t i = 0; i < _number_customers; ++i) {
    is_queue = false;
    for (auto it = queues_customers->begin();
        it != queues_customers->end() ; ++it) {
      if ((*it)->size() < _queue_length) {
        (*it)->push(_customer());
        is_queue = true;
        break;
      }
    }
    if (!is_queue) {
      auto temporary_queue = new std::queue<Customer*>;
      temporary_queue->push(_customer());
      queues_customers->push_back(temporary_queue);
      threads.push_back(new
      std::thread(&Shop::_serve_queue, this, temporary_queue));
    }
  }
}
