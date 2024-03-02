#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    Stack<int> test;
    for (int i = 0; i < 5; i++) {
        test.push(i);
    }
    cout << test.top() << endl;
    while (!test.empty()) {
        cout << test.top() << endl;
        test.pop();
    }

}