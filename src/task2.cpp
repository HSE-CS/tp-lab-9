//  Copyright 2021 GHA created by Klykov Anton

#include "task2.h"

std::mutex mu;
std::condition_variable cv;
bool finished{false};
bool sorted{false};
bool printed{true};

void bubble_sort(std::vector<std::string>& vector_string,
                 std::function<bool(std::string,
                     std::string)> lambda_function) {
  std::string temp;
  for (size_t i = 0; i < vector_string.size() - 1; i++) {
    for (size_t j = 0; j < vector_string.size() - i - 1;
    j++) {
      std::unique_lock<std::mutex> lg(mu);
      cv.wait(lg, []() {return printed;});
      if (lambda_function(vector_string[j],
                          vector_string[j + 1])) {
        temp = vector_string[j];
        vector_string[j] = vector_string[j + 1];
        vector_string[j + 1] = temp;
      }
      finished = true;
      printed = false;
      lg.unlock();
      cv.notify_all();
    }
  }
  sorted = true;
}
