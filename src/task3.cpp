//Copyright NikDemoShow 2021
#include"task3.h"
void Shop::work(){
  for (unsigned int i{ 0 }; i < this->buyerscnt; ++i) {
    buyer* newB{ new buyer };
    for (int j{ 0 }; j < std::rand() % 5 + 5; ++j) {
      newB->purch.push_back(std::rand() % 100);
    }
    this->buyers.insert(newB);
  }
  unsigned int time{ 0 };
  while (this->buyers.size() || this->cashBoxes.size()) {
    for (std::set<buyer*>::iterator b = this->buyers.begin();
      b != this->buyers.end();) {
      if ((*b)->timeToPay <= time) {
        bool wasAdd{ false };
        mu.lock();
        for (std::set<std::pair<std::thread*,
          std::queue<buyer*>*>>::iterator cb = this->cashBoxes.begin();
          cb != this->cashBoxes.end();) {
          if (!(*cb).second->size()) {
            cb = this->cashBoxes.erase(cb);
          } else {
            if ((*cb).second->size() < this->lim) {
              (*cb).second->push(*b);
              std::cout << "add buyer to " <<
                (*cb).first->get_id() << std::endl;
              wasAdd = true;
            }
            cb++;
          }
        }
        mu.unlock();
        if (!wasAdd) {
          std::queue<buyer*>* newQ{ new std::queue<buyer*> };
          newQ->push(std::move(*b));
          std::thread* newT{ new std::thread(cbwork, newQ)};
          std::cout << "create cb" << std::endl;
          std::cout << "add the first buyer to " <<
            newT->get_id() <<  std::endl;
          this->cashBoxes.insert({ newT, newQ });
        }
        b = this->buyers.erase(b);
      } else {
        ++b;
      }
    }
    for (std::set<std::pair<std::thread*,
      std::queue<buyer*>*>>::iterator cb = this->cashBoxes.begin();
      cb != this->cashBoxes.end();) {
      if (!(*cb).second->size()) {
        cb = this->cashBoxes.erase(cb);
      } else {
        ++cb;
      }
    }
    std::cout << this->buyers.size() << ' ' <<
      this->cashBoxes.size() << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    time++;
  }
}
void cbwork(std::queue<buyer*>* buyers) {
  while (buyers->size()) {
    for (auto el : buyers->front()->purch) {
      std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    buyers->pop();
  }
  std::cout << "cb " << std::this_thread::get_id() << " finish" << std::endl;
}
