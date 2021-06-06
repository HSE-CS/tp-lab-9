// Copyright 2021 DBarinov
#include "task3.h"

void Shop::CustomerRun(Customer* _customer, int _id) {
	int random = std::rand() % 5000;
	std::mutex a;
	for (int i = 0; i < _customer->list.size(); i++) {
		std::this_thread::sleep_for(std::chrono::milliseconds(random));
		std::unique_lock<std::mutex> lock(a);
		CustomerPrint(_id, i);
		lock.unlock();
	}
}
void Shop::CustomerPrint(int _id, int i) {
	std::cout << std::this_thread::get_id()
		<< "-" << _id << "-" << i + 1 << std::endl;
}
void Shop::QueueRun(std::queue <Customer*>* _customers) {
	int id = 1;
	while (!_customers->empty()) {
		auto customer = _customers->front();
		CustomerRun(customer, id);
		id++;
	}
	delete _customers;
}
Customer* Shop::newCustomer() {
	int number_of_deals = std::rand() % 10 + 1;
	std::vector<int> list_;
	for (int i = 0; i < number_of_deals; i++) {
		list_.push_back(std::rand() % 300 + 1);
	}
	return new Customer(list_);
}
void Shop::ShopRun() {
	int random = std::rand() % 1500;
	for (int i = 0; i < limit; i++) {
		bool IT = false;
		for (auto customer = customers.begin(); customer != customers.end(); customer++) {
			std::this_thread::sleep_for(std::chrono::milliseconds(random));
			if ((*customer)->size() < 10 && (*customer) != nullptr) {
				(*customer)->push(newCustomer());
				IT = true;
				break;
			}
			else if ((*customer) == nullptr) {
				customers.erase(customer);
			}
		}
		if (IT == false) {
			std::queue <Customer*>* queue_ptr = new std::queue <Customer*>;
			queue_ptr->push(this->newCustomer());
			customers.push_back(queue_ptr);
			threads.push_back(new std::thread(&Shop::QueueRun, this, queue_ptr));
		}
	}
	for (auto thread : threads) {
		thread->join();
	}
}
