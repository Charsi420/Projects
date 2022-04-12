#include <iostream>
#include "Stack.h"
using namespace std;
int main() {
    cout << "Hello, World!" << endl;
    Stack<int> ob;
    ob.push(23);
    cout << ob.pop();
    return 0;
}
