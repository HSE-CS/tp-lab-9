// Copyright 2021 alexgiving

#include "task3.h"

void Supermarket::BuyerRun(Buyer* buyer, int buyer_id) {
  std::mutex a;
  for (size_t product_id = 0; product_id < buyer->list.size(); ++product_id) {
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::unique_lock<std::mutex> unqLock(a);
    BuyerPrint(buyer_id, product_id);
    unqLock.unlock();
  }
}

void Supermarket::BuyerPrint(int buyer_id, int product_id) {
  std::cout << std::this_thread::get_id() << "\t" << buyer_id
  <<"\t" << ++product_id << std::endl;
}

void Supermarket::QueueRun(std::queue <Buyer*>* buyers_queue) {
  size_t buyer_id = 1;
  while (!buyers_queue->empty()) {
    auto new_buyer = buyers_queue->front();
    BuyerRun(new_buyer, buyer_id++);
    // The same
//    BuyerRun(new_buyer, buyer_id);
//    ++buyer_id;
  }
  delete buyers_queue;
}

Buyer* Supermarket::createBuyer() {
  std::vector<int> list;
  int purchases_number = std::rand() % 9 + 1;
  list.reserve(purchases_number);
  for (size_t i = 0; i < purchases_number; ++i)
    list.push_back(std::rand() % 10 + 1);
  return new Buyer(list);
}

void Supermarket::SupermarketRun() {
  for (size_t i = 0; i < MN; ++i) {
    bool FQ = false;
    for (auto buyer = buyers.begin(); buyer != buyers.end(); ++buyer) {
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
      if ((*buyer)->size() < 10 && (*buyer) != nullptr) {
        (*buyer)->push(createBuyer());
        FQ = true;
        break;
      } else if ((*buyer) == nullptr) buyers.erase(buyer);
    }
    if (!FQ) {
      auto* _queue_ptr = new std::queue <Buyer*>;
      _queue_ptr->push(this->createBuyer());
      buyers.push_back(_queue_ptr);
      threads.push_back(new std::thread(&Supermarket::QueueRun,
                                        this, _queue_ptr));
    }
  }
  for (auto thread : threads) thread->join();
}
