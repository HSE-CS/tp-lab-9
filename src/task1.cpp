
#include <iostream>
#include <functional>
#include <vector>

#include "task1.h"

using namespace std;


template <typename T>
void Swap(T& a, T& b);

void BubbleSort(vector <string>& array, const function <bool (string, string)>& Compare){
    for(unsigned int i = 0; i < array.size(); i++){
        for(unsigned int j = 0; j < array.size() - 1 - i; j++){
            if (Compare(array[j], array[j+1])){  // Left > Right -> Swap
                    Swap<string>(array[j], array[j+1]);
            }
        }
    }
}

template <typename T>
void Swap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}