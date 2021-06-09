// Copyright 2021 Vadukk
#include "task2.h"

int main() {
    std::vector<std::string> vec = { "hello", "book", "language",
     "programming", "window", "camera", "car" };
    BubbleSort(vec, [](std::string s1, std::string s2)
        {return s1.length() > s2.length(); });
}