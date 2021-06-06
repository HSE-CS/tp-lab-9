// Copyright NikDemoShow 2021
#include"task2.h"
void Bsort(std::vector<std::string>& objects,
  const std::function<bool(std::string, std::string)> comp,
  bool& done, std::mutex& mu,
  std::condition_variable& cv) {
  for (size_t i{ 0 }; i < objects.size(); ++i) {
    for (size_t j{ 0 }; j < objects.size(); ++j) {
      if (comp(objects[i], objects[j])) {
        {
          std::lock_guard <std::mutex> lg(mu);
          std::swap(objects[i], objects[j]);
        }
        cv.notify_all();
      }
    }
  }
  {
    std::lock_guard<std::mutex> lg(mu);
    done = true;
  }
  cv.notify_all();
}
