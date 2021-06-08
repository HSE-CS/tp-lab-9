  // Copyright 2021 kisozinov

#include <iostream>
#include "task1.h"

int main() {
    std::vector<std::string> source_vector{ "You", "Have", "the",
        "right", "to", "remain", "silent" };

    std::function<bool(const std::string &, const std::string &)> comparator1 =
        [](const std::string &a, const std::string &b) {
        return a.length() < b.length();
    };

    std::function<bool(const std::string &, const std::string &)> comparator2 =
        [](const std::string &a, const std::string &b) {
        return a < b;
    };

    std::function<bool(const std::string &, const std::string &)> comparator3 =
        [](const std::string &a, const std::string &b) {
        return a[0] < b[0];
    };

    std::function<bool(const std::string &, const std::string &)> comparator4 =
        [](const std::string &a, const std::string &b) {
        return a[a.size()] < b[b.size()];
    };

    std::function<bool(const std::string &, const std::string &)> comparator5 =
        [](const std::string &a, const std::string &b) {
        return a[a.size()] - a[0] < b[b.size()] - b[0];
    };

    print(bubbleSort(source_vector, comparator1));
    print(bubbleSort(source_vector, comparator2));
    print(bubbleSort(source_vector, comparator3));
    print(bubbleSort(source_vector, comparator4));
    print(bubbleSort(source_vector, comparator5));
    return 0;
}
