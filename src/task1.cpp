// Copyright NikDemoShow 2021
#include"task1.h"
void Bsort(std::vector<std::string>* objects, const std::function<bool(std::string, std::string)> comp) {
  for (size_t i{ 0 }; i < objects->size(); ++i) {
    for (size_t j{ 0 }; j < objects->size(); ++j) {
      if (comp((*objects)[i], (*objects)[j])) {
        std::swap((*objects)[i], (*objects)[j]);
      }
    }
  }
}
