  // Copyright 2021 kisozinov

#include "task1.h"

std::vector<std::string> bubbleSort(const std::vector<std::string> &vec,
    std::function<bool(std::string, std::string)> comparator) {
    std::vector<std::string> res(vec);
    for (unsigned i = 0; i < res.size(); ++i) {
        for (unsigned j = 0; j < res.size() - 1; ++j) {
            if (comparator(res[j], res[j + 1])) {
                auto temp = res[j];
                res[j] = res[j + 1];
                res[j + 1] = temp;
            }
        }
    }
    // sort(vec.begin(), vec.end(), comparator);
    return res;
}

void print(std::vector<std::string> vec) {
    std::cout << "[";
    for (auto str : vec) {
        std::cout << "'" << str << "', ";
    }
    std::cout << "]\n" << std::endl;
}
