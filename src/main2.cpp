
#include <iostream>
#include <vector>

#include "task2.h"

using namespace std;

int main(){

    vector <string> array;
    array.emplace_back("the longest");
    array.emplace_back("middle one");
    array.emplace_back("short");
    array.emplace_back("sh");

    ThreadSort(array, [] (const string& a, const string& b) {return a.size()>b.size();});

    return 0;
}