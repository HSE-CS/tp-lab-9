//  Copyright Baklanov 2021
#include "task2.h"

void bubblesort2(const std::vector<std::string>& vec,
    std::function<bool(std::string, std::string)> comparator) {
    std::vector<std::string> v(vec);
    std::mutex a;
    for (unsigned int i = 0; i < v.size() - 1; ++i) {
        std::thread th([&v, &comparator, &a, &i]() {
            for (unsigned int j = 0; j < v.size() - i - 1; ++j) {
                if (comparator(v[j], v[j + 1])) {
                    a.lock();
                    std::string temp = v[j];
                    v[j] = v[j + 1];
                    v[j + 1] = temp;
                    a.unlock();
                }
            }
        });
        th.join();
        print(v);
    }
}

void print(std::vector<std::string> v) {
    for (std::string a : v) {
        std::cout << a << "   " << a.length() << std::endl;
    }
    std::cout << "\n";
}
