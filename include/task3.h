// Copyright 2021 DBarinov
#ifndef INCLUDE_TASK3_H_
#define INCLUDE_TASK3_H_
#include <iostream>
#include <vector>
#include <mutex>
#include <queue>
#include <thread>

class Customer {
public:
	std::vector<int> list;
	explicit Customer(std::vector<int> _list) {
		list = _list;
	}
};

class Shop {
private:
	std::vector<std::queue<Customer*>*> customers;
	std::vector<std::thread*> threads;
	int limit = 100;

public:
	Shop() {};
	Customer* newCustomer();
	void CustomerRun(Customer* _customer, int _id);
	void CustomerPrint(int _id, int i);
	void QueueRun(std::queue <Customer*>* _customers);
	void ShopRun();
};

#endif  //  INCLUDE_TASK3_H_