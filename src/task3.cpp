// Copyright Slavokeru 2021
#include"task3.h"
void SM::run() {
  for (unsigned int i{ 0 }; i < this->cnt; ++i) {
    buyer* newB{ new buyer };
    for (int j{ 0 }; j < std::rand() % 10 + 7; ++j) {
      newB->purch.push_back(std::rand() % 50);
    }
    this->buyers.insert(newB);
  }
  unsigned int t{ 0 };
  while (this->buyers.size() || this->Kass.size()) {
    for (std::set<buyer*>::iterator b = this->buyers.begin();
      b != this->buyers.end();) {
      if ((*b)->pay <= t) {
        bool wasAdd{ false };
        m.lock();
        for (std::set<std::pair<std::thread*,
          std::queue<buyer*>*>>::iterator cb = this->Kass.begin();
          cb != this->Kass.end();) {
          if (!(*cb).second->size()) {
            cb = this->Kass.erase(cb);
          } else {
            if ((*cb).second->size() < this->limit) {
              (*cb).second->push(*b);
              std::cout << "new buyer" << std::endl;
              wasAdd = true;
            }
            cb++;
          }
        }
        m.unlock();
        if (!wasAdd) {
          std::queue<buyer*>* newQ{ new std::queue<buyer*> };
          newQ->push(std::move(*b));
          std::thread* newT{ new std::thread(cbrun, newQ)};
          std::cout << "create kass" << std::endl;
          this->Kass.insert({ newT, newQ });
        }
        b = this->buyers.erase(b);
      } else {
        ++b;
      }
    }
    for (std::set<std::pair<std::thread*,
      std::queue<buyer*>*>>::iterator cb = this->Kass.begin();
      cb != this->Kass.end();) {
      if (!(*cb).second->size()) {
        cb = this->Kass.erase(cb);
      } else {
        ++cb;
      }
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    t++;
  }
}
void cbrun(std::queue<buyer*>* buyers) {
  while (buyers->size()) {
    for (auto el : buyers->front()->purch) {
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    buyers->pop();
  }
  std::cout << "Close kass"<< std::endl;
}
