// Copyright 2021 Schenikova

#include "task2.h"

int main() {
    // Words
    std::cout << "Words:" << std::endl;
    std::vector<std::string> words = {"please", "let", "me", "die", "i", "am",
    "tired", "of", "living", "this", "life"};
    // print(words);
    // by length
    std::cout << "by length:" << std::endl;
    BigBubbleSort(words, [](std::string x, std::string y)
        {return x.size() > y.size(); });
    // std::cout << "by first simbol:"<<std::endl;
    // BigBubbleSort(words, [](std::string x, std::string y)
    //     {return x[0] > y[0]; });
    // std::cout << "by last simbol:"<<std::endl;
    // BigBubbleSort(words, [](std::string x, std::string y)
    //     {return x.back() > y.back(); });
    return 0;
}
