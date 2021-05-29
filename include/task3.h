//  Copyright Baklanov 2021
#pragma once
#include <iostream>
#include <vector>
#include <mutex>
#include <thread>
#include <atomic>
#include <chrono>
#include <functional>
#include <string>
#include <queue>

class Client {
 private:
    std::vector<std::string> products;

 public:
    explicit Client(std::vector<std::string> products_) :
        products(products_) {}
    void addProduct(std::string product) {
        products.push_back(product);
    }
    std::string getProduct() {
        if (!products.empty()) {
            std::cout << products.size() << std::endl;
            std::string buf = products.back();
            products.pop_back();
            return buf;
        }
        return "";
    }
};

class Register {
 private:
    std::queue<Client*> clients;
    int number;
    bool full;
    bool jobisdone;

 public:
    Register() :
        number(0), full(false), jobisdone(false) {}
    void addClient(Client* client) {
        if (clients.size() == 5) {
            full = true;
        }
        clients.push(client);
    }
    void setNumber(int number_) {
        number = number_;
    }
    void serveClient(Client* client) {
        std::string buf = client->getProduct();
        while (!buf.empty()) {
            std::cout << buf << " Register - " << number << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(3000));
            buf = client->getProduct();
        }
    }
    void doServe() {
        while (!jobisdone) {
            if (!clients.empty()) {
                serveClient(clients.front());
                clients.pop();
            }
        }
    }
    bool isFull() {
        return full;
    }
    void setDone() {
        jobisdone = true;
    }
};

class Shop {
 private:
    std::vector<Register*> registers;

 public:
    std::thread* addRegister(Client* client);
    void closeRegister();
    void run(std::vector<Client*> clients);
};
