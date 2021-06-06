// Copyright 2021 kisozinov

#include "task2.h"

std::vector<std::string> bubbleSortTwoThread(
    const std::vector<std::string>& vec,
    std::function<bool(std::string, std::string)> comparator) {
    std::vector<std::string> res(vec);
    std::mutex a;
    for (auto i = 0; i < vec.size(); i++) {
        std::thread th([&res, &comparator, &a, &i]() {
            for (unsigned j = 0; j < res.size() - 1; j++)
                if (comparator(res[j], res[j + 1])) {
                    a.lock();
                    std::swap(res[j], res[j + 1]);
                    a.unlock();
                }
        });

        th.join();
        print(res);
    }
    return res;
}
