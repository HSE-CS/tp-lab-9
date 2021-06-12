// Copyright 12.06.21 DenisKabanov

#include "task3.h"

void Supermarket::BuyerRun(Buyer* buyer, int number) {
  int time = std::rand() % 100;
  std::mutex sync;
  for (int i = 0; i < buyer->list.size(); i++) {
    std::this_thread::sleep_for(std::chrono::milliseconds(time));
    std::unique_lock<std::mutex> unqLock(sync);
    BuyerPrint(number, i);
    unqLock.unlock();
  }
}

void Supermarket::BuyerPrint(int number, int i) {
  std::cout << std::this_thread::get_id() << "-" << number << "-" << i + 1
            << std::endl;
}

void Supermarket::QueueRun(std::queue<Buyer*>* buyers) {
  int id = 1;
  while (!buyers->empty()) {
    auto buyer = buyers->front();
    BuyerRun(buyer, id);
    id++;
  }
  delete buyers;
}

Buyer* Supermarket::createBuyer() {
  int PurchasesNumber = std::rand() % 10 + 1;
  std::vector<int> list_;
  for (int i = 0; i < PurchasesNumber; i++) {
    list_.push_back(std::rand() % 300 + 1);
  }
  return new Buyer(list_);
}

void Supermarket::SupermarketRun() {
  int time = std::rand() % 1500;
  for (int i = 0; i < maxNumber; i++) {
    bool FQ = false;
    for (auto buyer = buyers.begin(); buyer != buyers.end(); buyer++) {
      std::this_thread::sleep_for(std::chrono::milliseconds(time));
      if ((*buyer)->size() < 10 && (*buyer) != nullptr) {
        (*buyer)->push(createBuyer());
        FQ = true;
        break;
      } else if ((*buyer) == nullptr) {
        buyers.erase(buyer);
      }
    }
    if (FQ == false) {
      std::queue<Buyer*>* queue_ptr = new std::queue<Buyer*>;
      queue_ptr->push(this->createBuyer());
      buyers.push_back(queue_ptr);
      threads.push_back(
          new std::thread(&Supermarket::QueueRun, this, queue_ptr));
    }
  }
  for (auto thread : threads) {
    thread->join();
  }
}
