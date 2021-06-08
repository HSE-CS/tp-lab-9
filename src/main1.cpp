
#include <iostream>
#include <vector>
#include <algorithm>

#include "task1.h"

using namespace std;

void PrintArray(const vector <string>& array){
    for (auto const& elements : array){
        cout << elements << endl;
    }
    cout << endl;
}

int main() {

    vector <std::string> array;
    array.emplace_back("c string string string");
    array.emplace_back("a string long longer puper super string");
    array.emplace_back("r middle shorrrt");
    array.emplace_back("string");
    cout << endl << "Original: " << endl;
    PrintArray(array);

    cout << endl << "Alphabetic: " << endl;
    BubbleSort(array, [] (const string& a, const string& b) {return a[0] > b[0];});
    PrintArray(array);

    cout << endl << "Length: " << endl;
    BubbleSort(array, [] (const string& a, const string& b) {return a.size() > b.size();});
    PrintArray(array);

    cout << endl << "Rrrrrr-ness: " << endl;
    BubbleSort(array, [] (const string& a, const string& b) {
        unsigned int in_a = 0, in_b = 0;
        char character = 'r';
        for(auto const& ch:a){
            if(ch == character)
                in_a++;
        }
        for(auto const& ch:b){
            if(ch == character)
                in_b++;
        }
        return in_a > in_b;
    });
    PrintArray(array);

    cout << endl << "Count of words: " << endl;
    BubbleSort(array, [] (const string& a, const string& b) {
        unsigned int in_a = count(a.begin(), a.end(), ' ');
        unsigned int in_b = count(b.begin(), b.end(), ' ');
        return in_a > in_b;
    });
    PrintArray(array);

    cout << endl << "Substring: " << endl;
    BubbleSort(array, [] (const string& a, const string& b) {
        unsigned int in_a = 0, in_b = 0;
        string substr = "string";
        string::size_type pos = 0;
        while((pos = a.find(substr, pos)) != std::string::npos){
            in_a++;
            pos ++;
        }
        pos = 0;
        while((pos = b.find(substr, pos)) != std::string::npos){
            in_b++;
            pos ++;
        }
        return in_a > in_b;
    });
    PrintArray(array);

    return 0;
}