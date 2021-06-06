// Copyright 2021 MalininDmitry

#ifndef INCLUDE_TASK3_H_
#define INCLUDE_TASK3_H_
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <chrono>
#include <thread>

void shop3(std::vector<std::vector<int>> &persons, int max_queue) {
    std::queue<std::vector<int>> personsQueue1 = {};
    std::queue<std::vector<int>> personsQueue2 = {};
    std::queue<std::vector<int>> personsQueue3 = {};
    std::queue<std::vector<int>> personsQueue4 = {};
    std::vector<std::queue<std::vector<int>>> Queues ={personsQueue1, personsQueue2, personsQueue3, personsQueue4};
    bool cash1 = false;
    bool cash2 = false;
    
    while (!persons.empty()) {
        for (int i = 0; i < Queues.size(); i++) {
            if (Queues[i].size() < max_queue) {
                Queues[i].push(persons[0]);
                persons.erase(persons.begin());
                if (i == 0) {
                    if (!cash1) {
                        std::queue<std::vector<int>> *p = &Queues[i];
                        std::thread cas1([&cash1,p]() {
                            cash1 = true;
                            while (!(*p).empty()) {
                                std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                                std::cout << std::this_thread::get_id() << std::endl;
                                (*p).pop();
                            }
                            cash1 = false;
                        });
                        cas1.join();

                    } else if (i == 1) {
                        if (!cash2) {
                            std::queue<std::vector<int>> *p = &Queues[i];
                            std::thread cas2([&cash2,p]() {
                                cash2 = true;
                                while (!(*p).empty()) {
                                    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
                                    std::cout << std::this_thread::get_id() << std::endl;
                                    (*p).pop();
                                }
                                cash2 = false;
                            });
                            cas2.join();
                        }
                    }

                    break;
                }
            }
        }
    }
    
}


#endif  // INCLUDE_TASK3_H_
