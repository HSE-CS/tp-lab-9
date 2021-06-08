
#include <thread>
#include <vector>
#include <mutex>
#include <functional>
#include <iostream>

#include "task2.h"

using namespace std;

static void BubbleThread(vector <string>& array, const function <bool (string, string)>& Compare, bool& sorted);

template <typename T>
static void Swap(T& a, T& b);

mutex bubble;
mutex print;

static void PrintArray(const vector <string>& array){
    for (auto const& elements : array){
        cout << elements << endl;
    }
    cout << endl;
}

void ThreadSort(vector <string>& array,  const function <bool (string, string)>& Compare){


    bool sorted = false;
    thread sort(BubbleThread, ref(array), Compare, ref(sorted));

//    bubble.lock();    //  Locking the first step to sort begin without interfering with printing
                        //  Because print is unlocked, sort`s thread make a first step and unlock this mutex
    print.lock();       // Or we can lock the print, to start with printing. Depends on that we want to be the first
                        // If we`ve locked the print mutex, then we can start with printing the initial state of the array
                        // (Obviously, we don`t want to have a deadlock, so we should lock only one of them!!!)

    while(!sorted){

        bubble.lock();  //  Can`t print while bubble is locked. Bubble can be unlocked only from sort`s thread
                        //  So next iteration of printing can be only after the next iteration of sorting
        PrintArray(array);
        print.unlock(); //  Same as bubble mutex, but vise versa. Here we are "saying" that we printed this iteration
                        //  So sort`s thread can lock that mutex again -> can make next iteration of sorting

        // In general, it works like a ratchet mechanism - step by step
        // One phase let another happen, but the same step can`t happen after the same
    }

    sort.join();
    PrintArray(array);
}

static void BubbleThread(vector <string>& array, const function <bool (string, string)>& Compare, bool& sorted){

    for(unsigned int i = 0; i < array.size(); i++){
        for(unsigned int j = 0; j < array.size() - 1 - i; j++){
            print.lock();

            if (Compare(array[j], array[j+1])){  // Left > Right -> Swap
                Swap<string>(array[j], array[j+1]);
            }
            bubble.unlock();
        }
    }

    sorted = true;
}

template <typename T>
static void Swap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}
