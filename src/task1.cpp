// Copyright Slavokeru 2021
#include"task1.h"
void BS(std::vector<std::string>* vec,
  const std::function<bool(std::string, std::string)> comp) {
  for (size_t i{ 0 }; i < vec->size(); ++i) {
    for (size_t j{ 0 }; j < vec->size(); ++j) {
      if (comp((*vec)[i], (*vec)[j])) {
        std::swap((*vec)[i], (*vec)[j]);
      }
    }
  }
}
