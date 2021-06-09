// Copyright 2021 Rogov Andrey

#include "task1.h"


int main() {
    std::cout << "Words: " << std::endl;
    std::vector<std::string> words = { "hello", "world", "i",
    "am", "the", "star", "lord", "gaze", "upon", "my", "might" };
    print(words);

    std::cout << "by length:" << std::endl;
    words = BubbleSort(words, [](std::string x, std::string y)
    {return x.size() > y.size(); });
    print(words);

    words = { "hello", "world", "i", "am", "the", "star",
    "lord", "gaze", "upon", "my", "might" };
    std::cout << "by first symbol:" << std::endl;
    words = BubbleSort(words, [](std::string x, std::string y)
    {return x[0] > y[0]; });
    print(words);

    std::cout << "by last symbol:" << std::endl;
    words = BubbleSort(words, [](std::string x, std::string y)
    {return x.back() > y.back(); });
    print(words);

    std::cout << "by last symbol reverse:" << std::endl;
    words = BubbleSort(words, [](std::string x, std::string y)
    {return x.back() < y.back(); });
    print(words);

    std::cout << "by symbol in center:" << std::endl;
    words = BubbleSort(words, [](std::string x, std::string y)
    {return x[x.length() / 2] > y[y.length() / 2]; });
    print(words);
    return 0;
}
