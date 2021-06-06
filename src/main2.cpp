// Copyright 2021 kisozinov

#include "task2.h"

int main()
{
    std::vector<std::string> source_vector{ "You", "Have", "the",
        "right", "to", "remain", "silent" };


    std::function<bool(const std::string &, const std::string &)> comparator =
        [](const std::string &a, const std::string &b) {
        return a < b;
    };

    std::vector<std::string> res = bubbleSortTwoThread(source_vector, comparator);
    return 0;
}
