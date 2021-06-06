//  Copyright 2021 Nikita Naumov
#ifndef INCLUDE_TASK3_H_
#define INCLUDE_TASK3_H_

//  Include headers
#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <queue>
#include <mutex>
#include <typeinfo>

//  Constants
const int Max_queue_len = 5;
const int Customer_delay_ms = 1000;
const int Product_processing_delay = 500;
const int Max_quantity_of_customers = 30;

//  Classes
class Customer {
 private:
    std::vector<long> purchaseVector;

 public:
    Customer();
    ~Customer();
};

class Shop {
 private:
    std::vector<std::thread*> opennedThreads;
    std::vector<std::queue<Customer*>*> customerQueue;

 public:
    Shop();
    ~Shop();
    Customer* customerCreation();
    void processCustomer();

};

#endif  //  INCLUDE_TASK3_H_
