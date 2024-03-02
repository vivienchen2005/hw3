#include "heap.h"
#include <iostream>

using namespace std;

int main() {
    Heap<int, std::greater<int>> test;
    //for (int i = 0; i < 5; i++) {test.push(i);}

    test.push(0);
    test.push(2);
    test.push(1);
    test.push(5);
    test.push(4);

    cout << "top: " << test.top() << endl;
    cout << "size: " << test.size() << endl;
    cout << "empty: " << test.empty() << endl;
    while (!test.empty()) {
        cout << test.top() << endl;
        test.pop();
    }

}