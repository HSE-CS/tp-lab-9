//  Copyright 2021 by Kartseva Masha
#include "task2.h"
extern std::mutex mtx;
extern std::condition_variable cv;
extern bool finish, printed, sorted;
int main() {
    std::vector<std::string> vec = { "weekends", "summer", "hse", "exams", "weekdays", "or" };
    auto comparator = [](const std::string& a, const std::string& b) {
        return a.size() > b.size();
    };
    std::thread th(BubbleSort, ref(vec), comparator);
    while (!finish)
    {
        std::unique_lock<std::mutex> ul(mtx);
        cv.wait(ul, []() {return sorted; }); //while(!sorted)
        for (auto str : vec) {
            std::cout << str << " ";
        }
        std::cout << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(1500));
        printed = true;
        sorted = false;
        ul.unlock();
        cv.notify_all();
    }
    th.join();
    return 0;
}
