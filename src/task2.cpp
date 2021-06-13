// Copyright 2021 S

#include "task2.h"

void bubbleSortThreaded(const std::vector<std::string>& vector,
        std::function<bool(std::string, std::string)> comp) {
    std::vector<std::string> copyVector(vector);
    std::mutex mutex;
    for (int i = 0; i < vector.size(); i++) {
        std::thread thread([&copyVector, &comp, &mutex, &i]() {
            for (int j = 0; j < copyVector.size() - 1; j++)
                if (comp(copyVector[j], copyVector[j + 1])) {
                    mutex.lock();
                    std::string buffer = copyVector[j];
                    copyVector[j] = copyVector[j + 1];
                    copyVector[j + 1] = buffer;
                    mutex.unlock();
                }
        });
        thread.join();
        print(copyVector);
    }
}

void print(const std::vector<std::string>& vector) {
    for (auto string : vector) {
        std::cout << string << ", ";
    }
    std::cout << '\n';
}
