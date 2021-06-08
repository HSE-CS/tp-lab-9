// Copyright 2021 Rogov Andrey

#include "task2.h"


int main() {
    std::cout << "Words: " << std::endl;
    std::vector<std::string> words = { "hello", "world", "i", "am", "the", "star",
    "lord", "gaze", "upon", "my", "might" };

    std::cout << "by length:" << std::endl;
    BigBubbleSort(words, [](std::string x, std::string y)
    {return x.size() > y.size(); });

    return 0;
}
