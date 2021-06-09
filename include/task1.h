//  Copyright 2021 GHA created by Klykov Anton

#ifndef INCLUDE_TASK1_H_
#define INCLUDE_TASK1_H_

#include <functional>
#include <vector>
#include <string>
#include <cstring>

void BubbleSort(std::vector<std::string>& vector_string,
                const std::function<bool(std::string,
                    std::string)>& lambda_function);

#endif  // INCLUDE_TASK1_H_
