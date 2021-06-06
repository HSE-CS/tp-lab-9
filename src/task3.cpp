//  Copyright 2021 Nikita Naumov
#include "../include/task3.h"

Customer::Customer() {
    int quantityOfProducts = std::rand()%Max_products_quantity + 1;
    for (size_t i = 0; i < quantityOfProducts; ++i) {
        this->purchaseVector.push_back(std::rand());
    }
}
Customer::~Customer() {
    this->purchaseVector.erase(this->purchaseVector.begin(),
                                this->purchaseVector.end());
}

Customer* Shop::customerCreation() {
    return new Customer();
}

void Shop::processCustomer(Customer* objCustomer) {
    int counter = 0;
    for (auto item : objCustomer->purchaseVector) {
            std::this_thread::sleep_for(
                std::chrono::milliseconds(Product_processing_delay));
        std::mutex locker;
        locker.lock();
        std::cout << "Cashdesk id -> " << std::this_thread::get_id() <<
        std::endl << "Processed " << counter + 1 << " products of "
                << objCustomer->purchaseVector.size() << std::endl;
        ++counter;
        locker.unlock();
    }
}

void Shop::processQueue(std::queue<Customer*> currentQueue) {
    while (!(currentQueue.empty())) {
        auto currentCustomer = currentQueue.front();
        processCustomer(currentCustomer);
        currentQueue.pop();
    }
}

void Shop::processShop() {
    size_t quantityOfCustomers = 0;
    while (quantityOfCustomers < Max_quantity_of_customers) {
        std::this_thread::sleep_for
                    (std::chrono::milliseconds(Customer_delay_ms));
        bool notFullQueueExist = false;
        for (auto it = this->customerQueue.begin(); 
                    it != this->customerQueue.end(); ++it) {
            if ((*it)->size() < Max_queue_len) {
                notFullQueueExist = true;
                (*it)->push(customerCreation());
                ++quantityOfCustomers;
                break;
            }
        }
        if (!notFullQueueExist) {
            std::queue<Customer*>* objQueue = new std::queue<Customer*>;
            objQueue->push(customerCreation());
            this->customerQueue.push_back(objQueue);
            std::thread* thread = new std::thread(
                    [this, &objQueue](){Shop::processQueue(*objQueue);}
                );
            this->opennedThreads.push_back(thread);
        }
    }
    for (auto thread : this->opennedThreads) {
        thread->detach();
    }
}
