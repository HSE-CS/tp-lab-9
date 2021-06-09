//  Copyright 2021 GHA created by Klykov Anton

#include "task1.h"

void BubbleSort(std::vector<std::string>& vector_string,
                const std::function<bool(std::string,
                    std::string)>& lambda_function) {
  std::string temp;
  for (size_t i = 0; i < vector_string.size() - 1; i++) {
    for (size_t j = 0; j < vector_string.size() - i - 1; j++) {
      if (lambda_function(vector_string[j], vector_string[j + 1])) {
        temp = vector_string[j];
        vector_string[j] = vector_string[j + 1];
        vector_string[j + 1] = temp;
      }
    }
  }
}
