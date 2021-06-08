
#ifndef TP_LAB_9_TASK2_H
#define TP_LAB_9_TASK2_H

#include <functional>
#include <vector>

void ThreadSort(std::vector <std::string>& array, const std::function <bool (std::string, std::string)>& Compare);

#endif //TP_LAB_9_TASK2_H
