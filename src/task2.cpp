// Copyright Slavokeru 2021
#include"task2.h"
void BS(std::vector<std::string>& vec,
  const std::function<bool(std::string, std::string)> comp,
  bool& srt, std::mutex& m,
  std::condition_variable& c) {
  for (size_t i{ 0 }; i < vec.size(); ++i) {
    for (size_t j{ 0 }; j < vec.size(); ++j) {
      if (comp(vec[i], vec[j])) {
        {
          std::lock_guard <std::mutex> lg(m);
          std::swap(vec[i], vec[j]);
        }
        c.notify_all();
      }
    }
  }
  {
    std::lock_guard<std::mutex> lg(m);
    srt = true;
  }
  c.notify_all();
}
