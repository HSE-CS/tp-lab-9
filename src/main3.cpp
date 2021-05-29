//  Copyright Baklanov 2021
#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <mutex>
#include "task1.cpp"
#include "task2.cpp"
#include "task3.cpp"

void printsorted(std::vector<std::string> v) {
    std::cout << "{ ";
    for (std::string a : v) {
        std::cout << "\"" << a << "\"" << ", ";
    }
    std::cout << " }" << std::endl;
}

int main() {
    std::vector<std::string> v = { "milk",
        "orange",
        "bread", "meat", "fish" };
    std::vector<Client*> clients;
    for (int cl = 0; cl < 30; ++cl) {
        for (int i = 0; i < std::rand()% 5 + 1; ++i) {
            std::string buf;
            int maxrange = std::rand() % 10 + 1;
            for (int range = 0; range < maxrange; ++range) {
                buf.push_back(static_cast<char>(std::rand() % 254 + 1));
            }
            v.push_back(buf);
            buf = "";
        }
        Client* client = new Client(v);
        v.clear();
        clients.push_back(client);
    }
    Shop shop;
    shop.run(clients);
}
