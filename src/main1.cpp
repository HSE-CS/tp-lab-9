// Copyright 2021 Schenikova

#include "task1.h"

int main() {
    // Words
    std::cout << "Words:"<<std::endl;
    std::vector<std::string> words = {"please", "let", "me", "die", "i", "am",
    "tired", "of", "living", "this", "life"};
    print(words);
    // by length
    std::cout << "by length:"<<std::endl;
    words = BubbleSort(words, [](std::string x, std::string y)
        {return x.size() > y.size(); });
    print(words);
    // by first simbol
    std::cout << "by first simbol:"<<std::endl;
    words = BubbleSort(words, [](std::string x, std::string y)
        {return x[0] > y[0]; });
    print(words);
    // by last simbol
    std::cout << "by last simbol:"<<std::endl;
    words = BubbleSort(words, [](std::string x, std::string y)
        {return x.back() > y.back(); });
    print(words);
    // by last simbol reverse
    std::cout << "by last simbol reverse:"<<std::endl;
    words = BubbleSort(words, [](std::string x, std::string y)
        {return x.back() < y.back(); });
    print(words);
    // by simbol in the center
    std::cout << "by simbol in the center:"<<std::endl;
    words = BubbleSort(words, [](std::string x, std::string y)
        {return x[x.length() / 2] > y[y.length() / 2]; });
    print(words);
    return 0;
}
