// Copyright 2021 Schenikova

#include "task3.h"

Consumer::Consumer() {
  int productCount = std::rand() %  + 1;
  for (size_t i = 0; i < productCount; ++i) {
    this->addProduct();
  }
}
Consumer::~Consumer() {
  this->shops.erase(this->shops.begin(), this->shops.end());
}

void Shop::consumerRun(Consumer* currentConsumer, Shop* curShop) {
  int cnt = 0;
  for (auto s : currentConsumer->shops) {
    std::this_thread::sleep_for(std::chrono::milliseconds(std::rand() % 1001));
    std::mutex mut;
    mut.lock();
    std::cout << "Cashdesk " << std::this_thread::get_id() << " Item #" <<
      cnt + 1 << std::endl;
    cnt++;
    mut.unlock();
    }
}

void Shop::queueRun(std::queue<Consumer*> currentConsumers) {
  while(!(currentConsumers.empty())) {
    auto currentConsumer = currentConsumers.front();
    consumerRun(currentConsumer, this);
    currentConsumers.pop();
  }
}

void Shop::shopRun() {
  int ConsumerCount = 0;
  while (ConsumerCount < this->getMaxConsumers()) {
    std::this_thread::sleep_for(std::chrono::milliseconds(std::rand() % 501));
    bool flag = false;
    for (auto i = this->consumerQueues.begin(); i != this->consumerQueues.end(); ++i) {
      if ((*i)->size() < this->getQueueLen()) {
        flag = !flag;
        (*i)->push(new Consumer());
        ConsumerCount++;
        break;
      }
    }
    if (!flag) {
      std::queue<Consumer*>* _queue = new std::queue<Consumer*>;
      _queue->push(new Consumer());
      this->consumerQueues.push_back(_queue);
      std::thread* _thread = new std::thread([this, &_queue] ()
        {Shop::queueRun(*_queue);});
      this->myThreads.push_back(_thread);
    }
  }
  for (auto thread : this->myThreads) {
    thread->detach();
  }
}
